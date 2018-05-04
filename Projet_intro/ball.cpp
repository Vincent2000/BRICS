#include "Ball.h"
#include<GL/glu.h>

/*
* Constructeur de Game
* Ce que je fais...
*
* Inputs :
*
* Outputs :
*
*/
Ball::Ball(float x, float y, float z, float r, float a, float s)
{
    X_ = x;
    Y_ = y;
    Z_ = z;
    radius_ = r;
    angle_ = a;
    speed_ = s;
}

/*
* Constructeur de Game
* Ce que je fais...
*
* Inputs :
*
* Outputs :
*
*/
void Ball::move(float x, float y){
    X_=X_+x;
    Y_=Y_+y;
}

Ball::~Ball()
{
}

void Ball::appears(){
    GLUquadric *quadrique = gluNewQuadric();
    glPushMatrix();
    glTranslatef(X_, Y_ + radius_, Z_);
    glColor3f(250.0, 0.0, 0.0);
    gluSphere(quadrique, radius_, 20, 20);
    glPopMatrix();
    gluDeleteQuadric(quadrique);
}
