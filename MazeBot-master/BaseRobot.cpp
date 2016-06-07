

#ifndef BASEROBOT_C
#define BASEROBOT_C
#include "BaseRobot.h"

using namespace std;

void BaseRobot::loadMaze(Maze maze) {
    this->maze = maze;
}

void BaseRobot::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}

void BaseRobot::getStats() {
    cout << "Turns: " << turns << endl;
}

#endif