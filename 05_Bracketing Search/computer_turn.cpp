//Write a program that calculates a random number from 1 through 100.
//The program then asks the user to guess the number.
//If the user guesses too high or too low then the program should
//output "too high" or "too low" accordingly.
//The program must let the user continue to guess until the user correctly guesses the number.

//★ Modify the program to output how many guesses it took
//the user to correctly guess the right number.

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::cout; using std::cin;
using std::endl;

int main (){
    int secret, guess, guess_num = 0;

    srand (time(NULL));

    secret = rand() % 100 + 1;

    do {
        cout << "Guess the number (1 to 100): ";
        cin >> guess;

        if (guess < secret){
            cout << "Try a higher number." << endl;
        } else if (guess > secret){
            cout << "Try a lower number." << endl;
        }
        ++guess_num;
    } while (guess != secret);

    cout << "Congratulations!" << endl;
    cout << "It took you " << guess_num
        << " tries to find the correct number." << endl;

    return 0;
}