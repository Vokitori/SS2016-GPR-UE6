#include "Maze.h"
#include <fstream>
#include "termcolor.h"

using namespace std;

Maze::Maze(string filename) {
    ifstream infile(filename);
    string nextLine;

    while (getline(infile, nextLine)) {
        vector<int> newLine;
        for (int i = 0; i < nextLine.length(); i++) {
            if (nextLine[i] == ' ') {
                newLine.push_back(0);
            } else if (nextLine[i] == '#') {
                newLine.push_back(-1);
            }
        }
        if (newLine.size() != 0)
            addLine(newLine);
    }
    getStartAndEnd();
}

void Maze::start() {
    print();
}

void Maze::print() const {
    char c = ' ';
    for (int y = 0; y < board.size(); y++) {
        c = (y == 0 || y == board.size() - 1) ? '#' : ' ';
        for (int x = 0; x < board[y].size(); x++) {
            if (x == 0 || x == board[y].size() - 1)
                printBlock(y, x, '#');
            else printBlock(y, x, c);
        }
        cout << termcolor::reset << endl;
    }
    cout << "Start: <" << startX << ", " << startY << "> " << endl;
    cout << "End: <" << endX << ", " << endY << "> " << endl;

}

const bool Maze::isFinished(const Roboter * roboter) const {

}

const bool Maze::isEmpty(const Roboter* roboter, const int rx, const int ry) const {
    if (board[roboter->getX() + rx][roboter->getY() + ry] == -1) {
        return true;
    } else
        return false;

}

const bool Maze::isFrontEmpty(const Roboter * roboter) const {
    switch (roboter->getDirection()) {
        case NORTH:
            return isEmpty(roboter, 0, -1);
        case SOUTH:
            return isEmpty(roboter, 0, 1);
        case EAST:
            return isEmpty(roboter, 1, 0);
        case WEST:
            return isEmpty(roboter, -1, 0);
        default:
            return false;
    }
}

const bool Maze::isBackEmpty(const Roboter * roboter) const {
    switch (roboter->getDirection()) {
        case NORTH:
            return isEmpty(roboter, 0, 1);
        case SOUTH:
            return isEmpty(roboter, 0, -1);
        case EAST:
            return isEmpty(roboter, -1, 0);
        case WEST:
            return isEmpty(roboter, 1, 0);
        default:
            return false;
    }
}

const bool Maze::isLeftEmpty(const Roboter * roboter) const {
    switch (roboter->getDirection()) {
        case NORTH:
            return isEmpty(roboter, -1, 0);
        case SOUTH:
            return isEmpty(roboter, 1, 0);
        case EAST:
            return isEmpty(roboter, 0, -1);
        case WEST:
            return isEmpty(roboter, 0, 1);
        default:
            return false;
    }

}

const bool Maze::isRightEmpty(const Roboter * roboter) const {
    switch (roboter->getDirection()) {
        case NORTH:
            return isEmpty(roboter, 1, 0);
        case SOUTH:
            return isEmpty(roboter, -1, 0);
        case EAST:
            return isEmpty(roboter, 0, 1);
        case WEST:
            return isEmpty(roboter, 0, -1);
        default:
            return false;
    }

}

const int Maze::getIntAt(const int x, const int y) const {
    return board[x][y];
}

const char Maze::printBlock(const int x, const int y, const char c) const {
    int value = board[x][y];
    switch (value) {
        case -1:
            cout << termcolor::reset;
            break;
        case 0://WHITE
            cout << termcolor::on_white;
            break;
        case 1://BLUE
            cout << termcolor::on_blue;
            break;
        case 2://YELLOW
            cout << termcolor::on_blue;
            break;
        case 3://GREEN
            cout << termcolor::on_green;
            break;
        case 4://RED
            cout << termcolor::on_red;
            break;
        case 5://MAGENTA
            cout << termcolor::on_magenta;
            break;
        case 6://GREEN
            cout << termcolor::on_cyan;
            break;
        case 7://GREY
            cout << termcolor::on_grey;
            break;
    }
    cout << c;
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
        int j = board.size() - 1;
        for (int i = 0; i < board[0].size(); i++) {
            if (getIntAt(j, i) != 0) continue;
            endX = j;
            endY = i;
            ce = true;
        }
    }
}