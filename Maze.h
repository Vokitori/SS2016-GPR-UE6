#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>

#include "termcolor.h"

#include "Roboter.h"

using namespace std;

class Maze {
public:

    vector<Roboter*> roboterList;

    Maze(string filename);
    void start();
    const bool isFinished(Roboter *roboter) const;
    const bool isFrontEmpty(Roboter *roboter) const;
    const bool isBackEmpty(Roboter *roboter) const;
    const bool isLeftEmpty(Roboter *roboter) const;
    const bool isRightEmpty(Roboter *roboter) const;
    void mark(Roboter *roboter);
    void printBoard() const;
    void printStartEnd() const;
    void printStepTable() const;
    
private:
    const char wall = '#';
    const char free = ' ';
    mutex m_mark;
    int startX = 0, startY = 0, endX = 0, endY = 0;
    vector<vector<int>> board;

    const bool isEmpty(Roboter *roboter, const int rx, const int ry) const;
    const char printBlock(const int x, const int y, const char c = ' ') const;
    void determineStartAndEndPoint();
};

#endif
