#include "Roboter.h"
#include <iostream>
#include "Maze.h"

Roboter::Roboter(int color) : color(color) {
}

Roboter::~Roboter() {
}

void Roboter::findExit(Maze maze) {

}

bool Roboter::action(Maze maze) {

}

bool Roboter::moveForward(Maze maze) {
    if (!maze.isFrontEmpty(this))
        return false;
    switch (direction) {
        case NORTH:
            y -= 1;
        case SOUTH:
            y += 1;
        case EAST:
            x += 1;
        case WEST:
            x -= 1;
        default:
            return false;
    }
    stepCount++;
    return true;
}

void Roboter::turnLeft() {
    int dir = direction;
    dir += 3;
    dir %= 4;
    direction = (Direction) dir;
}

void Roboter::turnRight() {
    int dir = direction;
    dir += 1;
    dir %= 4;
    direction = (Direction) dir;
}

void Roboter::turnAround() {
    int dir = direction;
    dir += 2;
    dir %= 4;
    direction = (Direction) dir;
}

const Direction Roboter::getDirection() const {
    return direction;
}

const int Roboter::getStepCount() const {
    return stepCount;
}

const int Roboter::getX() const {
    return x;
}

const int Roboter::getY() const {
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

bool Roboter_right::action(Maze maze) {

}

void Roboter::testString() {
    std::cout<<"vererbung geht"<<std::endl;
}



//second robot "Roboter_left"

Roboter_left::~Roboter_left() {

}

void Roboter_left::findExit(Maze maze) {

}

bool Roboter_left::action(Maze maze) {

}


//third robot "Roboter_third"

Roboter_three::~Roboter_three() {

}

void Roboter_three::findExit(Maze maze) {

}

bool Roboter_three::action(Maze maze) {

}

