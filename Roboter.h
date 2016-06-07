#ifndef ROBOTER_H
#define ROBOTER_H

#include <thread>

class Maze;

class Roboter {
public:
    Roboter(int color);
    virtual ~Roboter();
    virtual void findExit();
    int steps = 0;
    int color;
    int x, y;
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
    void findExit() override;
private:

};

class Roboter_left : public Roboter {
public:

    Roboter_left(int color) : Roboter(color) {
    };
    ~Roboter_left();
    void findExit() override;
private:

};

class Roboter_three : public Roboter {
public:

    Roboter_three(int color) : Roboter(color) {
    };
    ~Roboter_three();
    void findExit() override;
private:

};
#endif /* ROBOTER_H */
