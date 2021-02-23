#ifndef GUARD_DUNGEON
#define GUARD_DUNGEON

#include <string>
#include <vector>

struct Entity{
    int xAxis = 1, yAxis = 1, life = 1;
    char name = ' ';
};

class Dungeon {
public:
    Dungeon()
        { initBoard(); }
    Dungeon(const int totalRows, const int totalCols)
        { initBoard(totalRows, totalCols); }
    
    void initBoard(const int x = 10, const int y = 10);
    void initTraps(int&);
    void initEnemys(int&);          //++++++++++++++++
    void print();
    void moveEnemy();               //++++++++++++++++
    int movePlayer(int, int);
    Entity getPlayer() { return player; }

private:
    std::vector<std::vector<char>> coords;
    std::vector<Entity> entitys;
    Entity player;
};

#endif