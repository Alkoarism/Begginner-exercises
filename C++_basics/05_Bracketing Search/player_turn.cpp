//Write a program that calculates a random number from 1 through 100.
//The program then asks the user to guess the number.
//If the user guesses too high or too low then the program should
//output "too high" or "too low" accordingly.
//The program must let the user continue to guess until the user correctly guesses the number.

//★ Modify the program to output how many guesses it took
//the user to correctly guess the right number.

//★★ Modify the program so that instead of the user guessing a number
//the computer came up with, the computer guesses the number that the
//user has secretely decided. The user must tell the
//computer whether it guesed too high or too low.

//★★★★ Modify the program so that no matter what number the user thinks of
//(1-100) the computer can guess it in 7 or less guesses.


#include <iostream>
#include <string>

using std::cout; using std::cin;
using std::endl; using std::string;

void options ();

int main (){
    cout << "Choose a number ranging from 1 to 100."
        << "\nThe computer will try to guess the number."
        << "\nYou can either input:";
    options ();
    
    string choice;
    char i;
    int guess = 50;
    int tries = 0;
    float lastg = 50;
    bool gamestate = false;
    while (true){
        cin >> choice;
        if (!choice.empty()){
            i = choice[0];
        } else{
            i = 'z';
        }

        switch (i){
        case 'b':
            if (gamestate){
                cout << "A game is already in progress.";
            } else {
                gamestate = true;
            }
        break;
        case 'h':
            if (gamestate)
                guess += lastg;
        break;
        case 'l':
            if (gamestate)
                guess -= lastg;
        break;
        case 'c':
            if (gamestate){
                cout << "Yay. The computer won!"
                    << "\nIt just had to try "
                    << tries << " times!" << endl;
                guess = 50;
                lastg = 50;
                tries = 0;
                gamestate = false;
            }
        break;
        case 'e':
            cout << "Thanks for playing, goodbye.";
            return 0;
        break;
        default:
            cout << choice << " is not a valid input!"
                << "These are the valid entries: ";
            options();
        break;
        }

        if (gamestate){
            if (lastg > 2){
                lastg /= 2;
                int i = lastg;
                if (lastg - i > .5){
                    lastg = i + 1;
                }
            } else {
                lastg = 1;
            }
            cout << "The number is: " << guess << endl;
            ++tries;
        } else {
            cout << "Input a command to either, start or end the game." << endl;
        }
    }
}

void options (){
    cout << "\n \"b\" to begin the guessing;"
        << "\n \"h\" so the computer will choose a higher number;"
        << "\n \"l\" so the computer will choose a lower number;"
        << "\n \"c\" if the correct number has been chosen;"
        << "\n \"e\" to end the game." << endl;
}