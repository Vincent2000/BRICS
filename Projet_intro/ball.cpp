#include "Ball.h"
#include<GL/glu.h>

/**
 * @brief Ball::Ball
 * Initialisation de paramètres
 * @param x
 * @param y
 * @param z
 * @param r
 * @param a
 * @param s pour la vitesse
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



/**
 * @brief Ball::~Ball
 */
Ball::~Ball()
{
}



/**
 * @brief Ball::move
 * Déplacement de la balle en fonction de :
 * @param x pour le abscisses
 * @param y pour les ordonnées
 */
void Ball::move(float x, float y){
    X_=X_+x;
    Y_=Y_+y;
}



/**
 * @brief Ball::appears
 * Fonction d'affichage de la balle
 */
void Ball::appears(){
    //gestion des couleurs des lampes sur l'objet
    GLfloat colorAmbiant_tab[] = {0.7, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiant_tab);
    GLfloat colorDiffuse_tab[] = {0.9, 0.0, 0.0, 100.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse_tab);
    GLfloat colorSpecular_tab[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR, colorSpecular_tab);
    glMaterialf(GL_FRONT, GL_SHININESS, 10);

    GLUquadric *quadrique = gluNewQuadric();
    glPushMatrix();
    glTranslatef(X_, Y_ + radius_, Z_);
    //glColor3f(250.0, 0.0, 0.0);
    gluSphere(quadrique, radius_, 20, 20);
    glPopMatrix();
    gluDeleteQuadric(quadrique);

}
