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
    Dungeon(const int totalRows, const int totalCols, const int totalTraps)
        { initBoard(totalRows, totalCols, totalTraps); }
    
    void initBoard(const int x = 10, const int y = 10, const int traps = 10);
    void initEnemys(const int, const char);
    void randomPositioning(Entity&);
    void print();
    int moveEnemys(const char);
    int movePlayer(const int,const int);
    void moveLimitCheck(const int&,const int&, Entity&);

    Entity getPlayer() { return player; }

private:
    std::vector<std::vector<char>> coords;
    std::vector<Entity> entitys;
    Entity player;
};

#endif