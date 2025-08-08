#pragma once

#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>
#include <curses.h>

typedef std::vector<std::vector<wchar_t>> MazeLayout;

class Maze {
    private:
        MazeLayout map;

    public:
        Maze()= default;

        void importMazeLayout(const std::string& filePath);
        MazeLayout& getMapState();
        void draw() const;
};