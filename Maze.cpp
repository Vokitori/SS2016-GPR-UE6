#include "Maze.h"

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
            board.push_back(newLine);
    }
    determineStartAndEndPoint();
}

void startRobot(Roboter* roboter, Maze* maze, int startX, int startY) {
    roboter->x = startX;
    roboter->y = startY;
    roboter->findExit(maze);
}

void Maze::start() {
    vector<thread*> freds;
    for (int i = 0; i < roboterList.size(); i++) {
        freds.push_back(new thread(startRobot, roboterList[i], this, startX, startY));
    }
    for (int i = 0; i < freds.size(); i++) {
        freds[i]->join();
        delete freds[i];
    }
    printBoard();
    printStartEnd();
    printStepTable();
}

void Maze::mark(Roboter* roboter) {
    m_mark.lock();
    if (board[roboter->y][roboter->x] == -1)
        return;
    if ((((unsigned int) board[roboter->y][roboter->x]) & ((unsigned int) roboter->getColor())) == (unsigned int) 0)
        board[roboter->y][roboter->x] += roboter->getColor();
    m_mark.unlock();
}

const bool Maze::isFinished(Roboter * roboter) const {
    return endX == roboter->x && endY == roboter->y;
}

// <editor-fold defaultstate="collapsed" desc="bool isXXXEmpty(Roboter * roboter)">

const bool Maze::isEmpty(Roboter* roboter, const int rx, const int ry) const {
    if (roboter->y + ry >= board.size() || roboter->y + ry < 0) {
        return false;
    }
    if (roboter->x + rx >= board[roboter->y + ry].size() || roboter->x + rx < 0) {
        return false;
    }
    return board[roboter->y + ry][roboter->x + rx] != -1;
}

const bool Maze::isFrontEmpty(Roboter * roboter) const {
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
            cout << roboter->getDirection();
            return false;
    }
}

const bool Maze::isBackEmpty(Roboter * roboter) const {
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

const bool Maze::isLeftEmpty(Roboter * roboter) const {
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

const bool Maze::isRightEmpty(Roboter * roboter) const {
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
}// </editor-fold>

void Maze::printBoard() const {
    char c = ' ';
    for (int y = 0; y < board.size(); y++) {
        c = (y == 0 || y == board.size() - 1) ? '#' : ' ';
        for (int x = 0; x < board[y].size(); x++) {
            bool occupied = false;
            for (int i = 0; i < roboterList.size(); i++) {
                if (roboterList[i]->x == x && roboterList[i]->y == y)
                    occupied = true;
            }
            if (occupied)
                printBlock(x, y, '@');
            else if (x == 0 || x == board[y].size() - 1)
                printBlock(x, y, '#');
            else printBlock(x, y, c);
        }
        cout << termcolor::reset << endl;
    }
}

void Maze::printStartEnd() const {
    cout << "Startpoint: [" << startX << ", " << startY << "] " << endl;
    cout << "Endpoint: [" << endX << ", " << endY << "] " << endl;
}

void Maze::printStepTable() const {
    for (int i = 0; i < roboterList.size(); i++) {
        cout << "Robot number "<< (i+1) << " had to walk " << roboterList[i]->getStepCount() << " steps to victory." << endl;
    }
}

const char Maze::printBlock(const int x, const int y, const char c) const {
    int value = board[y][x];
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
            cout << termcolor::on_yellow;
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

void Maze::determineStartAndEndPoint() {
    startX = -1;
    startY = -1;
    endX = -1;
    endY = -1;
    int x = 0;
    int y = 0;

    //top: left to right
    for (x = 0; x < board[y].size() && x >= 0; x++) {
        if (board[y][x] == 0) {
            if (startX == -1) {
                startX = x;
                startY = y;
            } else {
                endX = x;
                endY = y;
                return;
            }
        }
    }
    //left: top to bottom
    for (x--; y < board.size() && y >= 0; y++) {
        if (board[y][x] == 0) {
            if (startX == -1) {
                startX = x;
                startY = y;
            } else {
                endX = x;
                endY = y;
                return;
            }
        }
    }

    //bottom: right to left
    for (y--; x < board[y].size() && x >= 0; x--) {
        if (board[y][x] == 0) {
            if (startX == -1) {
                startX = x;
                startY = y;
            } else {
                endX = x;
                endY = y;
                return;
            }
        }
    }

    //left: bottom to top
    for (x++; y < board.size() && y >= 0; y--) {
        if (board[y][x] == 0) {
            if (startX == -1) {
                startX = x;
                startY = y;
            } else {
                endX = x;
                endY = y;
                return;
            }
        }
    }
}