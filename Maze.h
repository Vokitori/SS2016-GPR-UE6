#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>
#include "Roboter.h"

using namespace std;

class Maze {
public:
    Maze(string filename);
    void start();
    const bool isFinished(const Roboter *roboter);
    const bool isNorthEmpty(const Roboter *roboter);
    const bool isSouthEmpty(const Roboter *roboter);
    const bool isWestEmpty(const Roboter *roboter);
    const bool isEastEmpty(const Roboter *roboter);
    vector<Roboter> roboterList;

private:
    const char wall = '#';
    const char free = ' ';
    int startX = 0, startY = 0, endX = 0, endY = 0;
    vector<vector<int>> board;

    void print();
    const bool isEmpty(const Roboter *roboter, const int rx, const int ry);
    void addLine(vector<int> line);
    const int getIntAt(const int x, const int y);
    const char printBlock(const int x, const int y);
    void setIntAt(const int x, const int y, const int value);
    void getStartAndEnd();
};

#endif
