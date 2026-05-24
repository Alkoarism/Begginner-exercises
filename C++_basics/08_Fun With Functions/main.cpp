//Write a function titled say_hello() that outputs to the screen "Hello"
//★ Modify the function so that it takes an integer argument and says hello
//a number of times equal to the value passed to it.

//★★ Make another function that takes two integers arguments and then returns
//an integer that is the product of the two integers. (i.e., integer1: 4, Integer2: 5 returns: 20)

//★★★ Make a function called half() that takes an integer argument.
//The function must print the number it received to the screen, then the program should
//divide that number by two to make a new number. If the new number
//is greater than zero the function then calls the function half()
//passing it the new number as its argument. If the number is zero or less then the function exits

//Call the function half() with an argument of 100, the screen output should be
//100
//50
//25
//...
//...
//1.

#include <iostream>

using std::cout; using std::endl;

void say_hello(const int);
int mult(const int, const int);
void half(int);

int main(){
    say_hello(5);

    int result = mult(2, 5);
    cout << result << endl;

    half(100);

    return 0;
}

void say_hello(const int times){
    for(int i = 0; i < times; i++){
        cout << "Hello\n";
    }
}

int mult(const int x, const int y){
    return x*y;
}

void half(int x){
    cout << x << endl;
    x /= 2;

    if (x >= 1){
        half(x);
    }
}