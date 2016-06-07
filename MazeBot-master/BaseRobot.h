/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BaseRobot.h
 * Author: Benjamin
 *
 * Created on May 19, 2016, 9:06 PM
 */

#ifndef BASEROBOT_H
#define BASEROBOT_H

#include "Maze.h"


class BaseRobot {
   
public:
    virtual void solve();
    void getStats();
    
    void loadMaze(Maze);
    void setPos(int, int);
    
private:
    int turns;
    int x, y;
    Maze maze;
};


#endif /* BASEROBOT_H */

