#include "Dungeon.hpp"
#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main(){
    cout << "Seventh run- Still making the game playable.\n";

    double ver = 0.6;
    int enemys = 0;

    cout << "Welcome to my take on the"
         << " dungeon crawler exercise game.\n"
         << " ver.:" << ver
         << endl;

    Dungeon board;

    //enemy function testing
    cin >> enemys;
    board.initTraps(enemys);
    board.print();
    
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

    board.print();
    return 0;
}