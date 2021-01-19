#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include "generic.hpp"

using std::cin; using std::cerr;
using std::endl; using std::string;

bool simpleChoice (const string& desired1, const string& desired2){
    bool result = false;
    char choice = ' ';
    while (choice != '1' && choice != '2'){
        cin >> choice;
        switch (choice){
            case '1':
                result = true;
            break;
            case '2':
                result = false;
            break;
            default:
                cerr << choice << "is not a valid input."
                     <<"\nPlease, input 1 ("
                     << desired1 << ") or 2 ("
                     << desired2 << ")."
                     << endl;
                choice = 0;
            break;
        }
    }
    return result;
}

int randomNumber (const int& start, const int& end){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(start,end);

    return distribution(generator);
}

int factorial (const int& number){
    int copy = number;
    if (copy > 1){
        copy *= factorial(copy - 1);
    }

    std::cout << copy << endl;

    return copy;
}
