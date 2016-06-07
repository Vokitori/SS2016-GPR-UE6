



#ifndef MAZE_C
#define MAZE_C
#include "Maze.h"


int Maze::getAt(int x, int y) {
    return maze[x][y];
}

char Maze::getAtC(int x, int y) {
    int pos = maze[x][y];
    if(pos == 0)
        return free;
    if(pos == 1) 
        return wall;
}

void Maze::setAt(int x, int y, int value) {
    maze[x][y] = value;
}

void Maze::addLine(vector<int> line) {
    maze.push_back(line);
    size++;
}

void Maze::getSE() {
    bool cs = false, ce = false;
    for(int i = 0; i < maze[0].size(); i++) {
        if(getAt(0,i) == 0) {
            startx = 0;
            starty = i;
            cs = true;
        }
    }
    if(!cs) {
        int i = maze[0].size()-1;
        for(int j = 0; j < maze.size(); j++) {
            if(getAt(j,i) == 0) {
                startx = j;
                starty = i;
                cs = true;
            }
        }
    
    } 
    
        int i = maze[0].size()-1;
        
        for(int j = 0; j < maze.size() - 1; j++) {
            if(getAt(j,i) == 0) {
                endx = j;
                endy = i;
                ce = true;
            }
        }
        
        if(!ce) {
            int j = maze.size() - 2;
            for(int i = 0; i < maze[0].size(); i++) {
                if(getAt(j,i) == 0) {
                    endx = j;
                    endy = i;
                    ce = true;
                }
            }
        }
        
    
    
}

#endif