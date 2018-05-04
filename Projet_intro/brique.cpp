#include "Brique.h"
#include<GL/glu.h>


Brique::Brique(int i, int j, float w, float h, float d)
{
    width_ = w;
    height_ = h;
    depth_ = d;
    X_ = i*(width_ + 3);
    Y_ = j*(height_ + 3) + 50;
    Z_= 0.0;
}

Brique::~Brique()
{
}

bool Brique::isTouched(Ball* ball) {
    //si la balle est en contact avec une surface verticale de la brique
    if ((X_ < ball->getX() + ball->getRadius() && ball->getX() - ball->getRadius() < X_ + width_) && Y_ < ball->getY() && ball->getY() < Y_ + height_)
    {
        ball->impactV();
        return true;
    }
    //si la balle est en contact avec une surface horizontale de la brique
    else if ((Y_ < ball->getY() + ball->getRadius() && ball->getY() - ball->getRadius() < Y_ + height_) && X_< ball->getX() && ball->getX() < X_ + width_)
    {
        ball->impactH();
        return true;
    }
    //si la balle est en contact avec un point de la brique
    if (pow(X_ - ball->getX(), 2) + pow(Y_ - ball->getY(), 2) < pow(ball->getRadius(), 2))
    {
        ball->setAngle((float) 3.1415 * 3 / 4);
//		angle = asin()
    //	ball->setAngle(3.1415 + 2 * angle - ball->getAngle());
        return true;
    }else if(pow(X_ + width_ - ball->getX(), 2) + pow(Y_ - ball->getY(), 2) <  pow(ball->getRadius(), 2))
    {
        ball->setAngle((float)3.1415 * 1 / 4);
        return true;
    }else if(pow(X_ - ball->getX(), 2) + pow(Y_ + height_ - ball->getY(), 2) <  pow(ball->getRadius(), 2))
    {
        ball->setAngle((float)3.1415 * (- 3 / 4));
        return true;
    }else if(pow(X_ + width_ - ball->getX(), 2) + pow(Y_ + height_ - ball->getY(), 2) <  pow(ball->getRadius(), 2))
    {
        ball->setAngle((float)3.1415 * (- 1 / 4));
        return true;
    }

    return false;
}

void Brique::appears(){

    //Face sur le plan Z=0
    glColor3ub(250.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(X_, Y_, Z_);
    glVertex3f(X_ + width_, Y_, Z_);
    glVertex3f(X_ + width_, Y_ + height_, Z_);
    glVertex3f(X_, Y_ + height_, Z_);
    glEnd();
    //Face su le plan Z=depth
    glColor3ub(0.0, 250.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(X_, Y_,  Z_ + depth_);
    glVertex3f(X_ + width_, Y_,  Z_ + depth_);
    glVertex3f(X_ + width_, Y_ + height_,  Z_ + depth_);
    glVertex3f(X_, Y_ + height_,  Z_ + depth_);
    glEnd();
    //Face sur le plan X=0
    glColor3ub(0.0, 0.0, 250.0);
    glBegin(GL_QUADS);
    glVertex3f(X_, Y_, Z_);
    glVertex3f(X_, Y_ + height_, Z_);
    glVertex3f(X_, Y_ + height_, Z_ + depth_);
    glVertex3f(X_, Y_, Z_ + depth_);
    glEnd();
    //Face sur le plan X=width
    glColor3ub(250.0, 250.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(X_ + width_, Y_, Z_);
    glVertex3f(X_ + width_, Y_ + height_, Z_);
    glVertex3f(X_ + width_, Y_ + height_, Z_ + depth_);
    glVertex3f(X_ + width_, Y_, Z_ + depth_);
    glEnd();
    //Face sur le plan Y=0
    glColor3ub(250.0, 0.0, 250.0);
    glBegin(GL_QUADS);
    glVertex3f(X_, Y_, Z_);
    glVertex3f(X_, Y_, Z_ + depth_);
    glVertex3f(X_ + width_, Y_, Z_ + depth_);
    glVertex3f(X_ + width_, Y_, Z_);
    glEnd();
    //Face sur le plan Y=height
    glColor3ub(0.0, 250.0, 250.0);
    glBegin(GL_QUADS);
    glVertex3f(X_, Y_ + height_, Z_);
    glVertex3f(X_, Y_ + height_, Z_ + depth_);
    glVertex3f(X_ + width_, Y_ + height_, Z_ + depth_);
    glVertex3f(X_ + width_, Y_ + height_, Z_);
    glEnd();
}
