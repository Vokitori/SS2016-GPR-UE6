#include <cstdlib>

#include "Maze.h"

using namespace std;

int main(int argc, char** argv) {
    Maze m1("maze_tests/maze1_small.txt");
    Maze m2("maze_tests/maze2_unicursal.txt");
    Maze m3("maze_tests/maze3_braid.txt");
    Maze m4("maze_tests/maze4_braid.txt");
    Maze m5("maze_tests/maze5_cavern.txt");
    m1.start();
    return 0;
}

