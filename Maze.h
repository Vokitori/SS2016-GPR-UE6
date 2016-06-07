#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>

class Maze {
public:
    Maze(const std::string &filename);
    virtual ~Maze();
    void start();
    
    std::vector<Roboter> roboterList;
    int ** world;
private:
    
};

#endif /* MAZE_H */

