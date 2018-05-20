#include "Wall.h"

/**
 * @brief Wall::Wall
 * @param xOrigine
 * @param yOrigine
 * @param zOrigine
 * @param xNormal
 * @param yNormal
 * @param zNormal
 * @param longueur
 * @param largeur
 * Constructeur de Wall
 * Initialisation du pointeur de surface_ avec ces paramètres
 * @author Vincent
 */
Wall::Wall(float xOrigine, float yOrigine, float zOrigine, float xNormal, float yNormal, float zNormal, float longueur, float largeur, QColor color)
{
    surface_ = new Surface(xOrigine, yOrigine, zOrigine, xNormal, yNormal, zNormal, longueur, largeur, color);
}

/**
 * @brief Wall::~Wall
 * Destructeur de Wall
 * Destruction du pointeur surface_
 * @author Vincent
 */
Wall::~Wall()
{
    surface_->~Surface();
}

/**
 * @brief Wall::appear
 * Fonction d'affichage du mur.
 * Elle utilise la fonction d'affichage de la classe surface pour afficher surface_
 * @author Vincent
 */
void Wall::appear(){
    getSurface()->Surface::appear();
}
