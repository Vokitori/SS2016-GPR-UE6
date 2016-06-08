#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include "Maze.h"

using namespace std;

int main(int argc, char** argv) {
   // string filename = argv[1];
    
    Maze m1("maze_tests/maze1_small.txt");
    Maze m2("maze_tests/maze2_unicursal.txt");
    Maze m3("maze_tests/maze3_braid.txt");
    Maze m4("maze_tests/maze4_braid.txt");
    Maze m5("maze_tests/maze5_cavern.txt");
    m3.start();
    return 0;
}

/*
 
 TODO:
 Makefile einbauen
 Roboter 1
 Roboter 2
 Roboter 3
 Parameter aus Commandline verwenden
 Maze.start() (Threads, Roboter starten)
 Tabelle Roboter stepCount
 Maze.markField(Roboter* r);
 
 */

