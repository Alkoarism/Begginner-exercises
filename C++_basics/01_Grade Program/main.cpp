//Write a program that allows the user to enter the grade scored in a programming class (0-100).
//If the user scored a 100 then notify the user that they got a perfect score.

//★ Modify the program so that if the user scored a 90-100 it informs the user that they scored an A

//★★ Modify the program so that it will notify the user of their letter grade
//0-59 F 60-69 D 70-79 C 80-89 B 90-100 A

#include <iostream>
#include <stdexcept>
#include <string>
#include "UX.hpp"

using std::string; using std::cout;
using std::cin; using std::endl;
using std::out_of_range;

int main(){

    greeting();

    float grade;
    cout << "Please insert your grade: ";
    cin >> grade;

    try{
        if (!((grade >= 0) && (100 >= grade))){
            throw out_of_range("The input is not a valid grade.");
        }
    } catch (out_of_range out){
        cout << out.what();
        return 1;
    }

    cout << "Your final score is: ";

    if (grade < 60)
        cout << "F!" << endl;
    
    else if (grade < 70)
        cout << "D!" << endl;
    
    else if (grade < 80)
        cout << "C!" << endl;

    else if (grade < 90)
        cout << "B!" << endl;
    
    else 
        cout << "A!" << endl;

    return 0;
}
