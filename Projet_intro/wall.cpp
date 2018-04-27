#include "Wall.h"

Wall::Wall(bool v, float p)
{
    vertical_ = v;
    position_ = p;
}

Wall::~Wall()
{
}

bool Wall::isTouched(Ball ball) {
    if (vertical_) {
        if (ball.getX() + ball.getRadius() > position_ || ball.getX() - ball.getRadius() < position_) return true;
        return false;
    }
    else {
        if (ball.getY() + ball.getRadius() > position_ || ball.getX() - ball.getRadius() < position_) return true;
        return false;
    }
};
