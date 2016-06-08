#include "Roboter.h"

#include <iostream>
#include "Maze.h"
#include <chrono>
#include <thread>

Roboter::Roboter(int color) : color(color) {
}

Roboter::~Roboter() {
}

void Roboter::findExit(Maze* maze) {
}

bool Roboter::action(Maze* maze) {
}

bool Roboter::moveForward(Maze* maze) {
    if (!maze->isFrontEmpty(this))
        return false;
    switch (direction) {
        case NORTH:
            y -= 1;
            break;
        case SOUTH:
            y += 1;
            break;
        case EAST:
            x += 1;
            break;
        case WEST:
            x -= 1;
            break;
        default:
            return false;
    }
    stepCount++;
    maze->mark(this);
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

const void Roboter::printRoboter() const {
    cout << "Roboter[" << "c: " << color << ", x:" << x << ", y:" << y << ", d: " << getDirectionString(direction) << ", s:" << stepCount << "]" << endl;
}

const Direction Roboter::getDirection() const {
    return direction;
}

const unsigned int Roboter::getStepCount() const {
    return stepCount;
}

const int Roboter::getColor() const {
    return color;
}



/*
 inherited robots
 
 */

//first robot "Roboter_right" 

Roboter_right::~Roboter_right() {

}

void Roboter_right::findExit(Maze* maze) {
    while (!maze->isFinished(this)) {
        action(maze);
       /* maze->print();
        printRoboter();
        getchar();*/
    }
}

bool Roboter_right::action(Maze* maze) {
    if (maze->isRightEmpty(this))
        turnRight();
    else if (maze->isFrontEmpty(this));
    else if (maze->isLeftEmpty(this))
        turnLeft();
    else turnAround();
    moveForward(maze);
    return !maze->isFinished(this);
}



//second robot "Roboter_left"

Roboter_left::~Roboter_left() {

}

void Roboter_left::findExit(Maze* maze) {

}

bool Roboter_left::action(Maze* maze) {

}


//third robot "Roboter_third"

Roboter_three::~Roboter_three() {

}

void Roboter_three::findExit(Maze* maze) {

}

bool Roboter_three::action(Maze* maze) {

}

