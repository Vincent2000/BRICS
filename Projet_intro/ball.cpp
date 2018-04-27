#include "Ball.h"

Ball::Ball(float x, float y, float r, float a, float s)
{
    X_ = x;
    Y_ = y+r;
    radius_ = r;
    angle_ = a;
    speed_ = s;
};

Ball::~Ball()
{
};
