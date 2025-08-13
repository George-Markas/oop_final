#include <chrono>
#include <thread>
#include "maze.h"
#include "entity.h"

// ReSharper disable once CppParameterMayBeConst
int main(int argc, char* argv[]) {
    Maze newMaze;
    if(argc > 1) {
        const std::string arg1 = argv[1];
        newMaze.importMazeLayout(arg1);
    } else {
        std::cerr << "Usage: " << argv[0] <<" <path_to_maze_layout_file>" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    start_color();
    use_default_colors();
#ifndef DEBUG
    curs_set(0);
#endif

    if(!has_colors()) {
        endwin();
        std::cerr << "Your terminal doesn't support colors" << std::endl;
        return EXIT_FAILURE;
    }

    init_pair(1, COLOR_RED, -1);

    Entity silver("Silver", 'S');
    // ReSharper disable once CppDFAEndlessLoop
    for(int i = 0; i < 1000; i++) {
        silver.randomSpawn(newMaze.getMapState());
        auto [x, y] = silver.getPos();

        // Round counter
        attron(COLOR_PAIR(1));
        mvprintw(0, static_cast<int>(newMaze.getMapState()[0].size()) + 1, "DOOM ");
        attroff(COLOR_PAIR(1));
        mvprintw(0 ,static_cast<int>(newMaze.getMapState()[0].size()) + 6, "is imminent... %d", 1000 - i);
        clrtoeol();

        newMaze.draw();
        newMaze.getMapState()[y][x] = ' ';
        std::this_thread::sleep_for(std::chrono::milliseconds(1300));
    }

    // TODO: add end screens
    endwin();

    return EXIT_SUCCESS;
}
