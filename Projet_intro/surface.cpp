#include "surface.h"
#include <GL/glu.h>

/**
 * @brief Surface::Surface
 * @param xOrigine
 * @param yOrigine
 * @param zOrigine
 * @param xNormal
 * @param yNormal
 * @param zNormal
 * @param longueur
 * @param largeur
 * Initialisation de la position de l'origine, des coordonées du vecteur normal à la surface, de la longeur, de la largeur, de la couleur et de l'angle de la normale
 * @author Vincent
 */
Surface::Surface(float xOrigine, float yOrigine, float zOrigine, float xNormal, float yNormal, float zNormal, float longueur, float largeur, QColor color){
    xOrigine_ = xOrigine;
    yOrigine_ = yOrigine;
    zOrigine_ = zOrigine;
    xNormal_ = xNormal;
    yNormal_ = yNormal;
    zNormal_ = zNormal;
    longueur_ = longueur;
    largeur_ = largeur;
    color_ = color;
    calculAngleNormal();
}


/**
 * @brief Surface::~Surface
 * @author Vincent
 */
Surface::~Surface(){
}


/**
 * @brief Surface::calculAngleNormal
 * @return l'angle de la normale
 * @author Vincent
 */
float Surface::calculAngleNormal(){
    angleNormal_ = 0.0;
    if (xNormal_ == 0 && yNormal_ == 1) {
        angleNormal_ = 3.14159/2;
    }
    else if (xNormal_ == 0 && yNormal_ == -1) {
        angleNormal_ = -3.14159/2;
    }
    else if (xNormal_ == 1 && yNormal_ == 0) {
            angleNormal_ = 0.0;
    }
    else if (xNormal_ == -1 && yNormal_ == 0) {
        angleNormal_ = 3.14159;
    }
}



/**
 * @brief Surface::appear
 * @param colorAmbiant_tab
 * @param colorDiffuse_tab
 * @param colorSpecular_tab
 * @author Vincent
 */
void Surface::appear(){
//    gestion des couleurs des lampes sur l'objet
    GLfloat colorAmbiant_tab[] = {(GLfloat) color_.red()/255, (GLfloat) color_.green()/255, (GLfloat) color_.blue()/255, (GLfloat) color_.alpha()/255};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiant_tab);
    GLfloat colorDiffuse_tab[] = {(GLfloat) 0.5 * color_.red()/255, (GLfloat) 0.5 * color_.green()/255, (GLfloat) 0.5 * color_.blue()/255, (GLfloat) color_.alpha()/255};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
    GLfloat colorSpecular_tab[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
    glMaterialf(GL_FRONT, GL_SHININESS, 10);

    //glColor3ub(color_.red(), color_.green(), color_.blue());
    glBegin(GL_QUADS);
    glVertex3f(xOrigine_, yOrigine_, zOrigine_);
    glVertex3f(xOrigine_ + longueur_ * abs(zNormal_), yOrigine_ + longueur_ * abs(xNormal_), zOrigine_ + longueur_ * abs(yNormal_));
    glVertex3f(xOrigine_ + longueur_ * abs(zNormal_) + largeur_ * abs(yNormal_), yOrigine_ + longueur_ * abs(xNormal_) + largeur_ * abs(zNormal_), zOrigine_ + longueur_ * abs(yNormal_) + largeur_ * abs(xNormal_));
    glVertex3f(xOrigine_ + largeur_ * abs(yNormal_), yOrigine_ + largeur_ * abs(zNormal_), zOrigine_ + largeur_ * abs(xNormal_));
    glEnd();
}



/**
 * @brief Surface::isTouched
 * @param ball
 * @return vrai si la surface est touchée et faux sinon
 * @author Vincent
 */
bool Surface::isTouched(Ball * ball) {
    if((abs( abs(xNormal_)*(xOrigine_ - ball->getX()) + abs(yNormal_)*(yOrigine_ - ball->getY())) <= ball->getRadius()) &&
       (0 <= abs(xNormal_)*(ball->getY() - yOrigine_) + abs(yNormal_)*(ball->getX() - xOrigine_)) &&
            (abs(xNormal_)*(ball->getY() - yOrigine_) + abs(yNormal_)*(ball->getX() - xOrigine_) <= abs(xNormal_)*longueur_ + abs(yNormal_)*largeur_)) return true;
    // Cas des arrêtes
    if(pow(ball->getX() - xOrigine_, 2) + pow (ball->getY() - yOrigine_, 2) <= pow (ball->getRadius(), 2)) return true;
    if(pow(ball->getX() - (xOrigine_ + abs(yNormal_) * largeur_), 2) + pow (ball->getY() - (yOrigine_ + abs(xNormal_) * longueur_), 2) <= pow (ball->getRadius(), 2)) return true;
//    if((yNormal_ * ball->getY() - ball->getRadius() + xNormal_ * ball->getX() <= yNormal_ * yOrigine_ + xNormal_ * xOrigine_) &&
//       (yNormal_ * ball->getY() + ball->getRadius() + xNormal_ * ball->getX() >= yNormal_ * yOrigine_ + xNormal_ * xOrigine_) &&
//      ((xOrigine_ < ball->getX() && ball->getX() < xOrigine_ + largeur_) || (yOrigine_ < ball->getY() && ball->getY() < yOrigine_ + longueur_))) return true;
    return false;
}
