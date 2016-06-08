#ifndef ROBOTER_H
#define ROBOTER_H

#include <thread>

class Maze;

enum Direction {
    NORTH = 0, EAST = 1, SOUTH = 2, WEST = 4
};

class Roboter {
public:
    int color;    
    
    Roboter(int color);
    virtual ~Roboter();
    virtual void findExit(Maze maze);
    
    int getX();
    int getY();
    int getSteps();
    Direction getDirection();
    
protected:
    int x, y;
    int steps = 0;
    Direction direction;
    
    bool moveForward(Maze maze);
    void turnLeft();
    void turnRight();
    void turnAround();
    
private:

};

/*
    inherited robots 
 */

class Roboter_right : public Roboter {
public:

    Roboter_right(int color) : Roboter(color) {
    };
    ~Roboter_right();
    void findExit(Maze maze) override;
protected:

private:

};

class Roboter_left : public Roboter {
public:

    Roboter_left(int color);
    ;
    ~Roboter_left();
    void findExit(Maze maze) override;
protected:

private:

};

class Roboter_three : public Roboter {
public:

    Roboter_three(int color) : Roboter(color) {
    };
    ~Roboter_three();
    void findExit(Maze maze) override;
protected:

private:

};
#endif /* ROBOTER_H */
