//Write a program that ccontinues to asks the user to enter any
//number other than 5 until the user enters the number 5.
//Then tell the user "Hey! you weren't supposed to enter 5!" and exit the program.

//★ Modify the program so that after 10 iterations if the user still
//hasn't entered 5 will tell the user "Wow, you're more patient than
//I am, you win." and exit.

//★★ Modify the program so that it asks the user to enter any number
//other than the number equal to the number of times they've been asked
//to enter a number. (i.e on the first iteration "Please enter any number
//other than 0" and on the second iteration "Please enter any number
//other than 1"m etc. etc. The program must behave accordingly exiting
//when the user enters the number they were asked not to.)

#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main (){

    cout << "Hello! ";

    int n = 1, i = 0;
    while ((n != (i - 1)) && (i < 10)){
        cout << "Please, insert any number other than "
        << i << ": ";
        cin >> n;
        i++;
    }

    if (i == 10)
        cout << "Wow, you are more patient than I am, you win.";
    else{
        cout << "Hey! You were not supposed to enter "
        << n << "!";
    }

    return 0;
}