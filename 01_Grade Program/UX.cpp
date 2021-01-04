#include <iostream>
#include <string>

using std::string; using std::cout;
using std::cin; using std::endl;

void greeting()
{
    string name;
    cout << "Please insert your name: ";
    cin >> name;
    cout << "\n Hello, " << name << "!" << endl;
}