#include "Maze.h"
#include "Roboter.h"

Maze::Maze(const string filename) {
    ifstream infile(filename);
    string nextLine;

    while (getline(infile, nextLine)) {
        vector<int> newLine;
        for (int i = 0; i < nextLine.length(); i++) {
            if (nextLine[i] == ' ') {
                newLine.push_back(-1);
            } else if (nextLine[i] == '#') {
                newLine.push_back(0);
            }
        }
        addLine(newLine);
    }
    getStartAndEnd();
}

void Maze::start() {
    for (int y = 0; y < board.size; y++) {
        for (int x = 0; x < board[y].size(); x++) {
            cout << getCharAt(y, x);
        }
        cout << endl;
    }
    cout << "Start: <" << startX << ", " << startY << "> " << endl;
    cout << "End: <" << endX << ", " << endY << "> " << endl;
}




const int Maze::getIntAt(const int x, const int y) {
    return board[x][y];
}

const char Maze::getCharAt(const int x, const int y) {
    int pos = board[x][y];
    if (pos == 0)
        return free;
    if (pos == 1)
        return wall;
}

void Maze::setIntAt(const int x, const int y, const int value) {
    board[x][y] = value;
}

void Maze::addLine(vector<int> line) {
    board.push_back(line);
}

void Maze::getStartAndEnd() {
    bool cs = false, ce = false;
    for (int y = 0; y < board[0].size(); y++) {
        if (getIntAt(0, y) != 0) continue;
        startX = 0;
        startY = y;
        cs = true;
    }
    if (!cs) {
        int x = board[0].size() - 1;
        for (int y = 0; y < board.size(); y++) {
            if (getIntAt(y, x) != 0)continue;
            startX = y;
            startY = x;
            cs = true;
        }
    }

    int x = board[0].size() - 1;

    for (int y = 0; y < board.size() - 1; y++) {
        if (getIntAt(y, x) != 0) continue;
        endX = y;
        endY = x;
        ce = true;
    }

    if (!ce) {
        int j = board.size() - 2;
        for (int i = 0; i < board[0].size(); i++) {
            if (getIntAt(j, i) != 0) continue;
            endX = j;
            endY = i;
            ce = true;
        }
    }
}