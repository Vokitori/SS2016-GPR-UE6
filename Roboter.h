#ifndef ROBOTER_H
#define ROBOTER_H

#include <thread>
#include <string>
class Maze;

enum Direction {
    NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3
};

static std::string getDirectionString(Direction dir) {
    const std::string directionStrings[] = {"N", "E", "S", "W"};
    return directionStrings[dir];
}

class Roboter {
public:
    
    unsigned int x,y;
    
    Roboter(int color);
    virtual ~Roboter();
    virtual void findExit(Maze *maze);
    
    const unsigned int getStepCount() const;
    const Direction getDirection() const;
    const int getColor() const;
    const void printRoboter() const;

protected:
    unsigned int stepCount = 0;
    int color;
    Direction direction = SOUTH;

    virtual bool action(Maze* maze);
    bool moveForward(Maze* maze);
    void turnLeft();
    void turnRight();
    void turnAround();
};

/*
    inherited robots 
 */

class Roboter_right : public Roboter {
public:
    Roboter_right(int color) : Roboter(color) {
    };

    ~Roboter_right();
    void findExit(Maze* maze) override;

protected:
    bool action(Maze* maze) override;

private:

};

class Roboter_left : public Roboter {
public:

    Roboter_left(int color) : Roboter(color) {
    };
    ~Roboter_left();
    void findExit(Maze* maze) override;

protected:
    bool action(Maze* maze) override;

private:

};

class Roboter_three : public Roboter {
public:

    Roboter_three(int color) : Roboter(color) {
    };
    ~Roboter_three();
    void findExit(Maze* maze) override;

protected:
    bool action(Maze* maze) override;

private:

};
#endif /* ROBOTER_H */
