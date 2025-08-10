#include "maze.h"

void Maze::importMazeLayout(const std::string& filePath) {
    // It is assumed the file uses '\n' for line separation
    std::wifstream layoutFile(filePath);
    if(!layoutFile.is_open()) {
        std::cerr << "Failed to open file" << filePath << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::wstring line;
    while(std::getline(layoutFile, line)) {
        std::vector<wchar_t> row(line.begin(), line.end());
        map.push_back(row);
    }

    layoutFile.close();
}

MazeLayout& Maze::getMapState() {
    return map;
}

void Maze::draw() const {
    for(int y = 0; y < map.size(); y++) {
        for(int x = 0; x < map[y].size(); x++) {
            //  Use Unicode full blocks for walls, print the rest as is
            wchar_t ch = (map[y][x] == L'*') ? L'█' : map[y][x];
            mvaddnwstr(y, x, &ch, 1);
        }
    }

    refresh();
}
