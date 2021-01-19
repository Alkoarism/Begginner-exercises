#ifndef GUARD_DUNGEON
#define GUARD_DUNGEON

#include <string>
#include <vector>

struct Entity{
    int axisX = 1, axisY = 1, life = 1;
    char name = ' ';
};

class Dungeon {
public:
    void initBoard(const int x = 10, const int y = 10);
    void initTraps(int&);
    void initEnemys(int&);          //++++++++++++++++
    void print();
    void moveEnemy();               //++++++++++++++++
    void movePlayer(int, int);
    int getVictory(){ return victory; }
    Entity getPlayer() { return player; }

private:
    int victory = 0;
    std::vector<std::vector<char>> coords;
    std::vector<Entity> entitys;
    Entity player;
};

#endif