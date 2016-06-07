#ifndef ROBOTER_H
#define ROBOTER_H

#include <thread>

class Maze;
class Roboter{
public:
    Roboter(int color);
    Roboter(const Roboter& orig);
    virtual ~Roboter();
    int steps = 0;
    int color;
private:

};

#endif /* ROBOTER_H */

