/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Maze.h
 * Author: Benjamin
 *
 * Created on May 19, 2016, 9:06 PM
 */

#ifndef MAZE_H
#define MAZE_H


#include <iostream>
#include <vector>

using namespace std;

class Maze {

public:
    void addLine(vector<int> line);
    int getAt(int x, int y); // 0 = free, 1 = wall  - may use for trails/notes
    char getAtC(int x, int y); // returns the char for printing
    void setAt(int x, int y, int value);
    void getSE(); // get Start, End
    int size = 0;
    int startx = 0, starty = 0, endx = 0, endy = 0; // x & y  coordinates of start/end of maze, get this in constructor
    
    vector< vector<int> >  maze;
    
private:
    char wall = '#';
    char free = ' ';
};



#endif /* MAZE_H */

