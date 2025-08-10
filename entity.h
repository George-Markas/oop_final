#pragma once

#include "maze.h"
#include <random>

typedef std::pair<int, int> Pos;

class Entity {
    private:
        wchar_t sprite;
        Pos currentPos;

    public:
        explicit Entity(wchar_t sprite);
        void randomSpawn(MazeLayout& map);
        Pos getPos();
        void setPos(int x, int y);
};
