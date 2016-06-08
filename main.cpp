#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include "Maze.h"

using namespace std;

int main(int argc, char** argv) {
//    int stupidTest = 0;
//    if (argc != 1) {
//        string mazeName = argv[1];
//        Maze *maze = new Maze(mazeName);
//
//        for (int i = 1; i < argc; i++) {
//            switch (argv[i][2]) {
//                case '1':{
//                    Roboter * r1 = new Roboter_left(1);
//                    maze->roboterList.push_back(r1);
//                    maze->roboterList[0]->printRoboter();
//                }
//                    break;
//                case '2':{
//                    
//                }
//                    break;
//                case '3':{
//                    
//                }
//                    break;
//                default:
//                    continue;
//            }
//
//        }
//    }


   // string filename = argv[1];
    Maze m1("maze_tests/maze1_small.txt");
    Maze m2("maze_tests/maze2_unicursal.txt");
    Maze m3("maze_tests/maze3_braid.txt");
    Maze m4("maze_tests/maze4_braid.txt");
    Maze m5("maze_tests/maze5_cavern.txt");
    Roboter* roboter = new Roboter_right(1);
    m3.roboterList.push_back(roboter);
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
 X Maze.markField(Roboter* r);
 
 */

