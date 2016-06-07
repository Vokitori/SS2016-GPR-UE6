/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MazeManager.h
 * Author: Benjamin
 *
 * Created on May 19, 2016, 9:06 PM
 */

#ifndef MAZEMANAGER_H
#define MAZEMANAGER_H

#include "Maze.h"
#include <iostream>
#include <vector>
#include <string>
        
using namespace std;

class MazeManager {

public:
    int addMaze(string filename);    
    Maze loadMaze(int id);
    void printMaze(int id);
    
private:
    vector<Maze> mazes;
};

#endif /* MAZEMANAGER_H */

