#include "Brique.h"
#include<GL/glu.h>

/**
 * @brief Brique::Brique
 * @param x
 * @param y
 * @param w
 * @param h
 * @param d
 * Constructeur de brique
 * Initialisation des paramètres de coordonées de son point d'origine, de ses dimensions (largeur, hauteru, profondeur) et des 5 surfaces.
 * @author Vincent
 */
Brique::Brique(float x, float y, float w, float h, float d, QColor color)
{
    width_ = w;
    height_ = h;
    depth_ = d;
    X_ = x;
    Y_ = y;
    Z_= 0.0;
    surfaceLeft_ = new Surface(x, y, 0, -1, 0, 0, h, d, color);
    surfaceRight_ = new Surface(x + w, y, 0, 1, 0, 0, h, d, color);
    surfaceBot_ = new Surface(x, y, 0, 0, -1, 0, d, w, color);
    surfaceTop_ = new Surface(x, y + h, 0, 0, 1, 0, d, w, color);
    surfaceForeground_ = new Surface(x, y, d, 0, 0, 1, w, h, color);
}



/**
 * @brief Brique::~Brique
 * Destructeur de Brique
 * @author Vincent
 */
Brique::~Brique()
{
    surfaceTop_->~Surface();
    surfaceBot_->~Surface();
    surfaceLeft_->~Surface();
    surfaceRight_->~Surface();
    surfaceForeground_->~Surface();
}



/**
 * @brief Brique::isTouched
 * @param ball
 * @return vrai si la brique est touchée sur une surface et dévie la balle en conséquence
 * @author Vincent
 */
bool Brique::isTouched(Ball * ball) {
    if(surfaceBot_->isTouched(ball)) return true;
    if(surfaceLeft_->isTouched(ball)) return true;
    if(surfaceTop_->isTouched(ball)) return true;
    if(surfaceRight_->isTouched(ball)) return true;
    return false;

//    if(surfaceBot_->isTouched(ball) || surfaceTop_->isTouched(ball)){
//        //ball->impactH();
//        return true;
//    }
//    else if(surfaceLeft_->isTouched(ball) || surfaceRight_->isTouched(ball)){
//        //ball->impactV();
//        return true;
//    }
//    return false;
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
 * @author Vincent
 */
void Brique::appears(){
    surfaceLeft_->appear();
    surfaceRight_->appear();
    surfaceBot_->appear();
    surfaceTop_->appear();
    surfaceForeground_->appear();
}
