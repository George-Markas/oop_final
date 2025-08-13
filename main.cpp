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

    Entity silver("Silver", 'S');
    int termini = 0;
    // ReSharper disable once CppDFAEndlessLoop
    while(true) {
        silver.randomSpawn(newMaze.getMapState());
        auto [x, y] = silver.getPos();
        mvprintw(0 ,static_cast<int>(newMaze.getMapState()[0].size()) + 1, "💀 %d/1000", termini);
        newMaze.draw();
        newMaze.getMapState()[y][x] = ' ';
        std::this_thread::sleep_for(std::chrono::milliseconds(1300));
        termini++;
    }

    getch();
    endwin();

    return EXIT_SUCCESS;
}
