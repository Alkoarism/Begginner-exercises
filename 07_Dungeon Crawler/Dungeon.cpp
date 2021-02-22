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
//    insert a size check routine on initBoard.
//    insert a input check on movePlayer.
//    test try and catch keywords use on later development steps
//    do not forget to make a more complete movePlayer function later
//    transform the entire program into a full OOP thing... maybe??

void Dungeon::initBoard (const int x, const int y){
    size rowCnt = x, colCnt = y;
    vector<char> xAxis;
    for (size j = 0; j != colCnt; ++j){
        xAxis.push_back('.');
    }

    for (size i = 0; i != rowCnt; ++i){
        coords.push_back(xAxis);
    }
    player.name = 'P';
    entitys.push_back(player);
    coords[1][1] = player.name;
    coords[rowCnt - 1][colCnt - 1] = 'X';
}

void Dungeon::initTraps(int& amount){
    int i = 0;
    while (i != amount){
        size row = 0,
            col = randomNumber (0, (coords.size())*(coords[0].size()));
        while (col > coords[0].size()){
            col -= coords[0].size();
            row++;
        }
        
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
    int yPos = player.yAxis + rowDir;
    int xPos = player.xAxis + colDir;
    coords[player.yAxis][player.xAxis] = '.';

    if (!(yPos < 0 || yPos >= coords.size())){
        player.yAxis = yPos;
    }
    if (!(xPos < 0 || xPos >= coords[0].size())) {
        player.xAxis = xPos;
    }

    entitys[0] = player;
    coords[player.yAxis][player.xAxis] = player.name;
}