#include <iostream>
#include <vector>
#include <string>
#include "Dungeon.hpp"
#include "generic.hpp"

using std::cout; using std::endl;
using std::vector; using std::string;
using std::cerr;

typedef vector<string>::size_type size;

//future corrections:
//      insert a size check routine on initBoard.
//      insert a input check on movePlayer.
//      test try and catch keywords use on later development steps
//      do not forget to make a more complete movePlayer function later
//      randomNumber function used on initTraps does not have a good random

void Dungeon::initBoard (const int x, const int y){
    size rowCnt = x, colCnt = y;
    vector<char> axisX;
    for (size j = 0; j != colCnt; ++j){
        axisX.push_back('.');
    }

    for (size i = 0; i != rowCnt; ++i){
        coords.push_back(axisX);
    }
    player.name = 'P';
    entitys.push_back(player);
    coords[1][1] = player.name;
    coords[rowCnt - 1][colCnt - 1] = 'X';
}

void Dungeon::initTraps(int& amount){
    int i = 0;
    while (i != amount){
        size row = randomNumber (0, coords.size() - 1),
            col = randomNumber (0, coords[0].size() - 1);
        
        if (coords[row][col] == '.'){
            coords[row][col] = 'T';
            i++;
        }
    }
}

void Dungeon::initEnemys(int& amount){

}

void Dungeon::print () {
    size rowCnt = coords.size(), colCnt = coords[0].size(),
        border = (coords[0].size() - 1);
    cout << endl;
    for (size i = 0; i != rowCnt; ++i){
        for (size j = 0; j != colCnt; ++j){
            cout << coords[i][j];
            if (j == border){
                cout << "\n";
            } else {
                cout << " ";
            }
        }
    }
    cout << "\n" << endl;
}

void Dungeon::moveEnemy(){

}

void Dungeon::movePlayer(int rowDir, int colDir){
    int yPos = player.axisY + rowDir;
    int xPos = player.axisX + colDir;
    coords[player.axisY][player.axisX] = '.';

    if (!(yPos < 0 || yPos >= coords.size())){
        player.axisY = yPos;
    }
    if (!(xPos < 0 || xPos >= coords[0].size())) {
        player.axisX = xPos;
    }

    entitys[0] = player;
    coords[player.axisY][player.axisX] = player.name;
}