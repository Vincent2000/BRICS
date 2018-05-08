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
//    GLfloat a [] = {0, 0.7, 0, 1};

   // GLfloat colorAmbiant_tab[] = {(GLfloat) getColor().red()/255, (GLfloat) getColor().green()/255, (GLfloat) getColor().blue()/255, (GLfloat) getColor().alpha()/255};
//    GLfloat colorDiffuse_tab[] = {0.7, 0.0, 0.0, 1.0};
//    GLfloat colorSpecular_tab[] = {1.0, 1.0, 1.0, 1.0};
    getSurface()->Surface::appear();
//    cout<<"Origine = "<<this->getXOrigine()<<", "<<this->getYOrigine()<<", "<<this->getZOrigine()<<endl;
//    cout<<"Normal = "<<this->getXNormal()<<", "<<this->getYNormal()<<", "<<this->getZNormal()<<endl;
//    cout<<"Longeur = "<<this->getLongueur()<<", Largeur = "<<this->getLargeur()<<endl<<endl<<endl;
}
