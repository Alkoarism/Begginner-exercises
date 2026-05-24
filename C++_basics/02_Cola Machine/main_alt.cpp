//Write a program that presents the user w/ a choice of your 5 favorite
//beverages (Coke, Water, Sprite, ... , Whatever).
//Then allow the user to choose a beverage by entering a number 1-5.
//Output which beverage they chose.

//★ If you program uses if statements instead of a switch statement,
//modify it to use a switch statement.
//If instead your program uses a switch statement, modify it to use if/else-if statements.

//★★ Modify the program so that if the user enters a choice other than 1-5
//then it will output "Error. choice was not valid, here is your money back."

#include <iostream>
#include <stdexcept>

using std::cout; using std::cin;
using std::endl; using std::out_of_range;

int main(){

    cout << "Hello! Please choose one of the following beverages: " << endl;
    cout << "1- Water\n"
    <<"2- Coke\n"
    <<"3- Sprite\n"
    <<"4- Cidra\n"
    <<"5- Wine" << endl;

    int option = 0;
    cin >> option;

    try{
        if (!((option > 0) && (6 > option))){
            throw out_of_range("Error. Choice was not valid, here is your money back.");
        }
    } catch (out_of_range out){
        cout << out.what();
        return 1;
    }

    cout << "You choose: ";
    if (option == 1)
        cout << "Water!";
    else if (option == 2)
        cout << "Coke!";
    else if (option == 3)
        cout << "Sprite!";
    else if (option == 4)
        cout << "Cidra!";
    else
        cout << "Wine!";

    return 0;
}