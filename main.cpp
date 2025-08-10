#include "maze.h"
#include "entity.h"

#ifdef DEBUG
#include <unistd.h>
#endif

int main() {
    Maze newMaze;
    newMaze.importMazeLayout(
        "/mnt/c/Users/George/CLionProjects/oop_final/maze_layout.txt");

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    start_color();
    use_default_colors();
    curs_set(0);

    if(!has_colors()) {
        endwin();
        std::cerr << "Colors are not supported by your terminal" << std::endl;
        return EXIT_FAILURE;
    }

#ifdef DEBUG
    // Entity random spawning test
    Entity silver('S');
    // ReSharper disable once CppDFAEndlessLoop
    while(true) {
        silver.randomSpawn(newMaze.getMapState());
        auto [x, y] = silver.getPos();
        newMaze.draw();
        newMaze.getMapState()[y][x] = ' ';
        sleep(2);
    }
#endif

    getch();
    endwin();

    return EXIT_SUCCESS;
}
