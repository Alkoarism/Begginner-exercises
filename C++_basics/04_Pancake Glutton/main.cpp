//Write a program that asks the user to enter the number of pancakes
//eaten for breakfast by 10 different people (Person 1, Person 2, ..., Person 10)
//Once the data has been entered the program must analyze
//the data and output which person ate the most pancakes for breakfast.

//★ Modify the program so that it also outputs which person ate the
//least number of pancakes for breakfast.

//★★★★ Modify the program so that it outputs a list in order
//of number of pancakes eaten of all 10 people.
//i.e.
//Person 4: ate 10 pancakes
//Person 3: ate 7 pancakes
//Person 8: ate 4 pancakes
//...
//Person 5: ate 0 pancakes

//★★★★★ Modify the program so it reads a list with the names and his/her number 
//of pancakes eaten from a separate file

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "glutton.hpp"

using std::string; using std::cin;
using std::cout; using std::vector;
using std::endl; using std::sort;
using std::ifstream; using std::ios;
using std::cerr;

int main(){

    char people_data[] = "people_data.list";
    ifstream inFile;

    inFile.open(people_data, ios::in);
    if (!inFile){
        cerr << "Can not open input file " << people_data << endl;
        return 1;
    }

    vector<glutton> gluttons;
    glutton g;

    while (inFile >> g.name >> g.ate){
        gluttons.push_back(g);
    }
    inFile.close();

    sort(gluttons.begin(), gluttons.end(), compare);

   typedef vector<glutton>::iterator it;
   it it_g = gluttons.end();
   while (it_g > gluttons.begin()){
       --it_g;
       cout << (*it_g).name << " " << (*it_g).ate << endl;       
   }

    return 0;
}