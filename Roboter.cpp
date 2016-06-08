#include "Roboter.h"

#include "Maze.h"

Roboter::Roboter(int color) : color(color) {
}

Roboter::~Roboter() {
}

void Roboter::findExit(Maze maze) {

}

bool Roboter::moveForward(Maze maze) {
}

void Roboter::turnLeft() {
    direction += 3;
    direction %= 4;
}

void Roboter::turnRight() {
    direction += 1;
    direction %= 4;
}

void Roboter::turnAround() {
    direction += 2;
    direction %= 4;
}

Direction Roboter::getDirection() {
    return direction;
}

int Roboter::getSteps() {
    return steps;
}

int Roboter::getX() {
    return x;
}

int Roboter::getY() {
    return y;
}


/*
 inherited robots
 
 */

//first robot "Roboter_right" 

Roboter_right::~Roboter_right() {

}

void Roboter_right::findExit(Maze maze) {

}



//second robot "Roboter_left"

Roboter_left::~Roboter_left() {

}

void Roboter_left::findExit(Maze maze) {

}



//third robot "Roboter_third"

Roboter_three::~Roboter_three() {

}

void Roboter_three::findExit(Maze maze) {

}


