#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>
#include "Roboter.h"

using namespace std;

class Maze {
public:

    vector<Roboter*> roboterList;

    Maze(string filename);
    void start();
    const bool isFinished(const Roboter *roboter) const;
    const bool isFrontEmpty(const Roboter *roboter) const;
    const bool isBackEmpty(const Roboter *roboter) const;
    const bool isLeftEmpty(const Roboter *roboter) const;
    const bool isRightEmpty(const Roboter *roboter) const;
    void mark(const Roboter *roboter);
    void print() const;
    
private:
    const char wall = '#';
    const char free = ' ';
    int startX = 0, startY = 0, endX = 0, endY = 0;
    vector<vector<int>> board;


    const bool isEmpty(const Roboter *roboter, const int rx, const int ry) const;
    void addLine(vector<int> line);
    const int getIntAt(const int x, const int y) const;
    const char printBlock(const int x, const int y, const char c = ' ') const;
    void setIntAt(const int x, const int y, const int value);
    void getStartAndEnd();
};

#endif
