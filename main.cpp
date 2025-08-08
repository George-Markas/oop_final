#include "maze.h"

int main() {
    Maze newMaze;
    newMaze.importMazeLayout(
        "/mnt/c/Users/George/CLionProjects/oop_final/maze_layout.txt");

    const MazeLayout map = newMaze.getMapState();

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    curs_set(0);

    if(!has_colors()) {
        endwin();
        std::cerr << "Colors are not supported by your terminal" << std::endl;
        return EXIT_FAILURE;
    }

    newMaze.draw();

    getch();
    endwin();

    return EXIT_SUCCESS;
}
