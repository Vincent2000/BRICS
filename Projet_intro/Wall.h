#ifndef WALL
#define WALL
#include"Ball.h"

class Wall
{
private:
    bool vertical_; //true for vertical, false for horizontal
    float position_; //the position
public:
    Wall(bool v = false, float p = 0);
	~Wall();
	bool isTouched(Ball ball); //return true is ball touch the wall, false else
    bool getVertical() { return vertical_; }
};

#endif // !WALL
