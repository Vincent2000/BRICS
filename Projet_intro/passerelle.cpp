#include "Passerelle.h"


/**
 * @brief Passerelle::Passerelle
 * @param x l'abscisse
 * @param y l'ordonnée
 * @param w la largeur
 * @param h la hauteur
 * @param d la profondeur
 * Appel au constructeur de Brique
 * @author Vincent
 */
Passerelle::Passerelle(float x, float y, float w, float h, float d, QColor color) : Brique(x, y, w, h, d, color)
{
}



/**
 * @brief Passerelle::move
 * Déplacement de la passerelle en fonction de :
 * @param x pour le abscisses
 * et déplacement des surfaces qui la composent
 * @author Vincent
 */
void Passerelle::move(float x, Wall * wallLeft, Wall * wallRight)
{
    float newPosition = getSurfaceLeft()->getXOrigine() + x;
    //Incrémentation selon x
    if (newPosition < wallLeft->getSurface()->getXOrigine()){
        newPosition = wallLeft->getSurface()->getXOrigine();
    }
    if (newPosition + getWidth() > wallRight->getSurface()->getXOrigine()){
        newPosition = wallRight->getSurface()->getXOrigine() - getWidth();
    }
    setX(newPosition);
    getSurfaceForeground()->setXOrigine(newPosition);
    getSurfaceLeft()->setXOrigine(newPosition);
    getSurfaceRight()->setXOrigine(newPosition + getWidth());
    getSurfaceBot()->setXOrigine(newPosition);
    getSurfaceTop()->setXOrigine(newPosition);
}



/**
 * @brief Passerelle::isTouched
 * @param ball
 * Détermine si la passerelle est touchée par la balle et modifie son angle de trajectoire selon son point d'impact
 * @return vrai si la passerelle est touchée
 * @author Vincent
 */
bool Passerelle::isTouched(Ball * ball){

//    if(getSurfaceTop()->isTouched(ball)) {
//        ball->setAngle( (ball->getX()-getX())/getWidth() * (2*1.0 - 3.14159) + 3.14159 - 1.0);
//        return true;
//    }
//    else if (getSurfaceRight() || getSurfaceLeft()){
//        ball->impactV();
//        return true;
//    }
    //si la balle est en contact avec une surface verticale de la brique
    if ((getX() < ball->getX() + ball->getRadius() && ball->getX() - ball->getRadius() < getX() + getWidth()) && getY() < ball->getY() && ball->getY() < getY() + getHeight())
    {
        ball->setAngle( (ball->getX()-getX())/getWidth() * (2*1.0 - 3.14159) + 3.14159 - 1.0);
        return true;
    }
    //si la balle est en contact avec une surface horizontale de la brique
    else if ((getY() < ball->getY() + ball->getRadius() && ball->getY() - ball->getRadius() < getY() + getHeight()) && getX()< ball->getX() && ball->getX() < getX() + getWidth())
    {
        ball->setAngle( (ball->getX()-getX())/getWidth() * (2*1.0 - 3.14159) + 3.14159 - 1.0);
        return true;
    }
    //si la balle est en contact avec un point de la brique

    //inferieur gauche
    if (pow(getX() - ball->getX(), 2) + pow(getY() - ball->getY(), 2) < pow(ball->getRadius(), 2))
    {
        ball->setAngle(-(float) 3.14159 * 3 / 4);
        return true;
    }

    //inferieur droit
    else if(pow(getX() + getWidth() - ball->getX(), 2) + pow(getY() - ball->getY(), 2) <  pow(ball->getRadius(), 2))
    {
        ball->setAngle(-(float)3.14159 * 1 / 4);
        return true;
    }

    //superieur gauche
    else if(pow(getX() - ball->getX(), 2) + pow(getY() + getHeight() - ball->getY(), 2) <  pow(ball->getRadius(), 2))
    {
        ball->setAngle((float)3.14159 * (3 / 4));
        return true;
    }

    //superieur droit
    else if(pow(getX() + getWidth() - ball->getX(), 2) + pow(getY() + getHeight() - ball->getY(), 2) <  pow(ball->getRadius(), 2))
    {
        ball->setAngle((float)3.14159 * (1 / 4));
        return true;
    }

    return false;
}

/**
 * @brief Passerelle::changeWitdth
 * @param w
 * Augmente ou diminue la largeur de la passerelle de w
 * Elle ne peut pas dépasser la taille du jeu et reste toujours positive
 * @author Vincent
 */
void Passerelle::changeWitdth(float w, float maximum){
    float newWidth = getWidth() + w;
    if(0 < newWidth && newWidth <= maximum) {
        setWidth(newWidth);
        getSurfaceForeground()->setLongueur(newWidth);
        getSurfaceRight()->setXOrigine(getSurfaceRight()->getXOrigine() + w);
        getSurfaceBot()->setLargeur(newWidth);
        getSurfaceTop()->setLargeur(newWidth);
    }
}
