//Write a program that asks for a user first name and last name separately.
//The program must then store the users full name inside a single string and out put it to the string.
//i.e.
//Input:
//John
//Smith
//Output:
//John Smith

//★ Modify the program so that it then replaces every a, e, i , o, u w/ the letter z.
//i.e.
//John Smith -> Jzhn Smzth

//★★ Modify the Program so that it reverses the users name
//i.e.
//John Smith -> htimS nhoJ

#include <iostream>
#include <string>
#include <limits>

using std::cin; using std::cout;
using std::endl;
using std::string;

typedef string::size_type size;

string input(const string&);
void clearOutput();

int main(){
    string fullName = " ", copy = " ";
    fullName = input("Input your first name: ");
    fullName += " ";
    fullName += input("Input your second name: ");

    copy = fullName;
    for (int i = 0; i < copy.size(); i++){
        //instead of tons of if else, use a single direct switch...
        switch (copy[i]){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                copy[i] = 'z';
            break;
        }
    }

    cout << copy << endl;

    for (size i = 0, j = (fullName.size() - 1); i < fullName.size()/2; i++, j--){
        char b = fullName[i], e = fullName[j];
        fullName[i] = e;
        fullName[j] = b;
    }

    cout << fullName << endl;

    return 0;
}

string input(const string& output){
    string input = " ";
    cout << output << endl;

    while (true){
        cin >> input;
        clearOutput();
        if(!cin.fail()){
            return input;
        } else {
            cout << "Not a valid input, try again." << endl;
        }
    }
}

void clearOutput()
{
    cin.clear();
    cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}