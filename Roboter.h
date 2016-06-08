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

    const int getX() const;
    const int getY() const;
    const int getStepCount() const;
    const Direction getDirection() const;

protected:
    int x, y;
    int stepCount = 0;
    Direction direction;
    
    virtual bool action(Maze maze);
    bool moveForward(Maze maze);
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
    void findExit(Maze maze) override;
    
protected:
    bool action(Maze maze) override;

private:

};

class Roboter_left : public Roboter {
public:

    Roboter_left(int color);
    ;
    ~Roboter_left();
    void findExit(Maze maze) override;
    
protected:
    bool action(Maze maze) override;

private:

};

class Roboter_three : public Roboter {
public:

    Roboter_three(int color) : Roboter(color) {
    };
    ~Roboter_three();
    void findExit(Maze maze) override;
    
protected:
    bool action(Maze maze) override;

private:

};
#endif /* ROBOTER_H */
