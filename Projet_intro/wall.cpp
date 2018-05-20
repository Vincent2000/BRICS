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
 * initialise le pointeur de surface_ avec ces paramètres
 */
Wall::Wall(float xOrigine, float yOrigine, float zOrigine, float xNormal, float yNormal, float zNormal, float longueur, float largeur, QColor color)//: Surface(xOrigine, yOrigine, zOrigine, xNormal, yNormal, zNormal, longueur, largeur)
{
    surface_ = new Surface(xOrigine, yOrigine, zOrigine, xNormal, yNormal, zNormal, longueur, largeur, color);
}

/**
 * @brief Wall::~Wall
 */
Wall::~Wall()
{
//    delete  surface;
}

/**
 * @brief Wall::appear
 * Fonction d'affichage du mur.
 * Elle utilise la fonction d'affichage de la classe surface pour afficher surface_
 */
void Wall::appear(){
    getSurface()->Surface::appear();
}
