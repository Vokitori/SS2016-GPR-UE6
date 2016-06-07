/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef MAZEMANAGER_C
#define MAZEMANAGER_C
#include "MazeManager.h"

#include <fstream>

using namespace std;

int MazeManager::addMaze(string filename) {

    Maze newMaze;

    ifstream infile(filename);

    string nextLine;
    
    while (getline(infile, nextLine))
    {
        vector<int> newLine;
        for(int i = 0; i < nextLine.length(); i++) {
            if(nextLine[i] == ' ') {
                newLine.push_back(0);
            } else if(nextLine[i] == '#') {
                newLine.push_back(1);
            }
        }
        cout << endl;
        newMaze.addLine(newLine);
    }
    
    newMaze.getSE();
    mazes.push_back(newMaze);
    return (mazes.size() - 1);
}


void MazeManager::printMaze(int id) {
    
    Maze maze = mazes[id];
    
    cout << "Maze #" << id << " found, printing: " << endl << endl; 
    
    for(int i = 0; i < maze.size; i++) {
        for(int j = 0; j < maze.maze[i].size(); j++) {
            cout << maze.getAtC(i, j);
        }
        cout << endl;
    }
    
    
    cout << "Start: <" << maze.startx << ", " << maze.starty << "> " << endl;
    cout << "End: <" << maze.endx << ", " << maze.endy << "> " << endl;
    
}

#endif