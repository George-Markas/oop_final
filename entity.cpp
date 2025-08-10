#include "entity.h"

Entity::Entity(const wchar_t sprite) {
    this->sprite = sprite;
}

Pos Entity::getPos() {
    return currentPos;
}

void Entity::setPos(int x, int y) {
    currentPos = {x, y};
}

void Entity::randomSpawn(MazeLayout& map) {
    // Find all valid positions
    std::vector<Pos> potentialSpawns;
    for(int y = 0; y < map.size(); y++) {
        for(int x = 0; x < map[y].size(); x++) {
            if(map[y][x] == ' ') {
                potentialSpawns.emplace_back(x, y);
            }
        }
    }

    // Pick a random valid position
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<std::mt19937::result_type> distrib(0
        , potentialSpawns.size() - 1);

    auto [x, y] = potentialSpawns[distrib(rng)];
    setPos(x, y);

    map[y][x] = sprite;
}