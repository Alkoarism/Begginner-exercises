#include "Dungeon.hpp"
#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main(){
    cout << "Sixth run- Making the game playable.";

    double ver = 0.5;

    Dungeon board;

    cout << "Welcome to my version of the"
         << " dungeon crawler exercise game."
         << " ver.:" << ver
         << endl;
    
    char direction = ' ';
    cin >> direction;

    switch (direction){
        case 'w':
            board.movePlayer(0, 1);
            break;
        case 'a':
            board.movePlayer(0, -1);
            break;
        case 's':
            board.movePlayer(-1, 0);
            break;
        case 'd':
            board.movePlayer(1, 0);
            break;
    }
    return 0;
}