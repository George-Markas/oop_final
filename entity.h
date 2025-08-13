#pragma once

#include "maze.h"
#include <random>

typedef std::pair<int, int> Pos;

class Entity {
    private:
        std::string prettyName;
        wchar_t sprite;
        Pos currentPos;

    public:
        explicit Entity(const std::string& prettyName, wchar_t sprite);
        void randomSpawn(MazeLayout& map);
        Pos getPos();
        void setPos(int x, int y);
};
