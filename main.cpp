#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#include "Maze.h"

using namespace std;

const string COLOR_BLACK = "0";
const string COLOR_BLUE = "1";
const string COLOR_GREEN = "2";
const string COLOR_AQUA = "3";
const string COLOR_RED = "4";
const string COLOR_PURPLE = "5";
const string COLOR_YELLOW = "6";
const string COLOR_WHITE = "7";
const string COLOR_GRAY = "8";
const string COLOR_LIGHT_BLUE = "9";
const string COLOR_LIGHT_GREEN = "A";
const string COLOR_LIGHT_AQUA = "B";
const string COLOR_LIGHT_RED = "C";
const string COLOR_LIGHT_PURPLE = "D";
const string COLOR_LIGHT_YELLOW = "E";
const string COLOR_BRIGHT_WHITE = "F";

void setTerminalColor(string textColor, string backgroundColor) {
    system("COLOR " + backgroundColor + textColor);
}

int main(int argc, char** argv) {
    Maze m1("maze_tests/maze1_small.txt");
    Maze m2("maze_tests/maze2_unicursal.txt");
    Maze m3("maze_tests/maze3_braid.txt");
    Maze m4("maze_tests/maze4_braid.txt");
    Maze m5("maze_tests/maze5_cavern.txt");
    m1.start();
    return 0;
}



