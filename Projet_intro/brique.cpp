#include "Brique.h"
#include<GL/glu.h>

/**
 * @brief Brique::Brique
 * @param x
 * @param y
 * @param w
 * @param h
 * @param d
 * Initialisation des paramètres de coordonées de son point d'origine, de ses dimensions (largeur, hauteru, profondeur) et des 5 surfaces.
 */
Brique::Brique(float x, float y, float w, float h, float d)
{
    width_ = w;
    height_ = h;
    depth_ = d;
    X_ = x;
    Y_ = y;
    Z_= 0.0;
    surfaceLeft_ = new Surface(x, y, 0, -1, 0, 0, h, d);
    surfaceRight_ = new Surface(x + w, y, 0, 1, 0, 0, h, d);
    surfaceBot_ = new Surface(x, y, 0, 0, -1, 0, d, w);
    surfaceTop_ = new Surface(x, y + h, 0, 0, 1, 0, d, w);
    surfaceForeground_ = new Surface(x, y, d, 0, 0, 1, w, h);
}



/**
 * @brief Brique::~Brique
 */
Brique::~Brique()
{
//    delete surfaceBot;
//    delete surfaceForeground;
//    delete surfaceLeft;
//    delete surfaceRight;
//    delete surfaceTop;
}



/**
 * @brief Brique::isTouched
 * @param ball
 * @return vrai si la brique est touchée sur une surface et dévie la balle en conséquence
 */
bool Brique::isTouched(Ball* ball) {
    if(surfaceBot_->isTouched(ball) || surfaceTop_->isTouched(ball)){
        ball->impactH();
        return true;
    }
    else if(surfaceLeft_->isTouched(ball) || surfaceRight_->isTouched(ball)){
        ball->impactV();
        return true;
    }
    return false;
//    //si la balle est en contact avec une surface verticale de la brique
//    if ((X_ < ball->getX() + ball->getRadius() && ball->getX() - ball->getRadius() < X_ + width_) && Y_ < ball->getY() && ball->getY() < Y_ + height_)
//    {
//        ball->impactV();
//        return true;
//    }
//    //si la balle est en contact avec une surface horizontale de la brique
//    else if ((Y_ < ball->getY() + ball->getRadius() && ball->getY() - ball->getRadius() < Y_ + height_) && X_< ball->getX() && ball->getX() < X_ + width_)
//    {
//        ball->impactH();
//        return true;
//    }
//    //si la balle est en contact avec un point de la brique

//    //inferieur gauche
//    if (pow(X_ - ball->getX(), 2) + pow(Y_ - ball->getY(), 2) < pow(ball->getRadius(), 2))
//    {
//        ball->setAngle(-(float) 3.14159 * 3 / 4);
//        return true;
//    }

//    //inferieur droit
//    else if(pow(X_ + width_ - ball->getX(), 2) + pow(Y_ - ball->getY(), 2) <  pow(ball->getRadius(), 2))
//    {
//        ball->setAngle(-(float)3.14159 * 1 / 4);
//        return true;
//    }

//    //superieur gauche
//    else if(pow(X_ - ball->getX(), 2) + pow(Y_ + height_ - ball->getY(), 2) <  pow(ball->getRadius(), 2))
//    {
//        ball->setAngle((float)3.14159 * (3 / 4));
//        return true;
//    }

//    //superieur droit
//    else if(pow(X_ + width_ - ball->getX(), 2) + pow(Y_ + height_ - ball->getY(), 2) <  pow(ball->getRadius(), 2))
//    {
//        ball->setAngle((float)3.14159 * (1 / 4));
//        return true;
//    }
//return false;
}



/**
 * @brief Brique::appears
 * Fonction d'affichage de la balle.
 * Elle affiche les 5 surfaces qui composent la brique
 */
void Brique::appears(){
    GLfloat a [] = {0, 0.7, 0, 1};
    surfaceLeft_->appear(a, a, a);
    surfaceRight_->appear(a, a, a);
    surfaceBot_->appear(a, a, a);
    surfaceTop_->appear(a, a, a);
    surfaceForeground_->appear(a, a, a);
    //    //Face sur le plan Z=0
    //    glColor3ub(250.0, 0.0, 0.0);
    //    glBegin(GL_QUADS);
    //    glVertex3f(X_, Y_, Z_);
    //    glVertex3f(X_ + width_, Y_, Z_);
    //    glVertex3f(X_ + width_, Y_ + height_, Z_);
    //    glVertex3f(X_, Y_ + height_, Z_);
    //    glEnd();
    //    //Face su le plan Z=depth
    //    glColor3ub(0.0, 250.0, 0.0);
    //    glBegin(GL_QUADS);
    //    glVertex3f(X_, Y_,  Z_ + depth_);
    //    glVertex3f(X_ + width_, Y_,  Z_ + depth_);
    //    glVertex3f(X_ + width_, Y_ + height_,  Z_ + depth_);
    //    glVertex3f(X_, Y_ + height_,  Z_ + depth_);
    //    glEnd();
    //    //Face sur le plan X=0
    //    glColor3ub(0.0, 0.0, 250.0);
    //    glBegin(GL_QUADS);
    //    glVertex3f(X_, Y_, Z_);
    //    glVertex3f(X_, Y_ + height_, Z_);
    //    glVertex3f(X_, Y_ + height_, Z_ + depth_);
    //    glVertex3f(X_, Y_, Z_ + depth_);
    //    glEnd();
    //    //Face sur le plan X=width
    //    glColor3ub(250.0, 250.0, 0.0);
    //    glBegin(GL_QUADS);
    //    glVertex3f(X_ + width_, Y_, Z_);
    //    glVertex3f(X_ + width_, Y_ + height_, Z_);
    //    glVertex3f(X_ + width_, Y_ + height_, Z_ + depth_);
    //    glVertex3f(X_ + width_, Y_, Z_ + depth_);
    //    glEnd();
    //    //Face sur le plan Y=0
    //    glColor3ub(250.0, 0.0, 250.0);
    //    glBegin(GL_QUADS);
    //    glVertex3f(X_, Y_, Z_);
    //    glVertex3f(X_, Y_, Z_ + depth_);
    //    glVertex3f(X_ + width_, Y_, Z_ + depth_);
    //    glVertex3f(X_ + width_, Y_, Z_);
    //    glEnd();
    //    //Face sur le plan Y=height
    //    glColor3ub(0.0, 250.0, 250.0);
    //    glBegin(GL_QUADS);
    //    glVertex3f(X_, Y_ + height_, Z_);
    //    glVertex3f(X_, Y_ + height_, Z_ + depth_);
    //    glVertex3f(X_ + width_, Y_ + height_, Z_ + depth_);
    //    glVertex3f(X_ + width_, Y_ + height_, Z_);
    //    glEnd();
}
