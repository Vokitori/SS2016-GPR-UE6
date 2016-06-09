#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include "Maze.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 1) {
        string mazeName = argv[1];
        if(!ifstream(mazeName)){
            cout << "File does not exist!" << endl;
            return -1;
        }
        Maze *maze = new Maze(mazeName);
        bool helpmode = false;
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] != '-')
                continue;
            if (argv[i][1] == 't')
                switch (argv[i][2]) {
                    case '1':
                    {
                        Roboter * r1 = new Roboter_right(1);
                        maze->roboterList.push_back(r1);
                    }
                        break;
                    case '2':
                    {
                        Roboter * r2 = new Roboter_left(2);
                        maze->roboterList.push_back(r2);
                    }
                        break;
                    case '3':
                    {
                        Roboter * r3 = new Roboter_three(4);
                        maze->roboterList.push_back(r3);
                    }
                        break;
                    default:
                        break;
                }
            if (argv[i][1] == 'h')
                helpmode = true;

        }
        if (helpmode) {
            cout << "Usage:" << endl;
            cout << "labrob <filename> [-t*][-h]" << endl;
            cout << "<filename>     path to map including filename" << endl;
            cout << "[-t*]          select robots, multiple at the same time allowed" << endl;
            cout << "                   * is an integer between 1 and 3" << endl;
            cout << "                   1 is rightbot (default), 2 is leftbot, 3 is advancedbot" << endl;
            cout << "[-h]           helptext" << endl;
        } else {
            if (maze->roboterList.size() == 0) {
                Roboter * r1 = new Roboter_right(1);
                maze->roboterList.push_back(r1);
            }
            maze->start();
        }
    }


    // string filename = argv[1];
    //Maze m1("maze_tests/maze1_small.txt");
   // Maze m2("maze_tests/maze2_unicursal.txt");
   // Maze m3("maze_tests/maze3_braid.txt");
   // Maze m4("maze_tests/maze4_braid.txt");
   // Maze m5("maze_tests/maze5_cavern.txt");
    // Roboter* r1 = new Roboter_right(1);
    // Roboter* r2 = new Roboter_left(2);

    //m3.roboterList.push_back(r1);
    // m3.roboterList.push_back(r2);

    // m3.start();
    return 0;
}

/*
 
 TODO:
 Makefile einbauen
 X Roboter 1
 X Roboter 2
 Roboter 3
 X Parameter aus Commandline verwenden
 X Maze.start() (Threads, Roboter starten)
 X Tabelle Roboter stepCount
 X Maze.markField(Roboter* r);
 X Memleaks finden und fixen
 X Input validieren
 X Helptext
 Kommentare
 Readme
 
 */

