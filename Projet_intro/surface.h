#ifndef SURFACE_H
#define SURFACE_H
#include <GL/glu.h>
#include<QColor>
#include"Ball.h"
#include<cmath>

class Surface
{
    //position de l'origine
    float xOrigine_;
    float yOrigine_;
    float zOrigine_;
    //Coordonées du vecteur normal
    float xNormal_;
    float yNormal_;
    float zNormal_;
    //Longeur et largeur
    float longueur_;
    float largeur_;
    QColor color_;
    float angleNormal_;


public:
    Surface(float xOrigine, float yOrigine, float zOrigine, float xNormal, float yNormal, float zNormal, float longueur, float largeur, QColor color);
    ~Surface();
    float calculAngleNormal();
    void appear();
    bool isTouched(Ball * ball); //return true is ball touch the wall, false else

//    Getters et Setters
    float getXOrigine() const { return xOrigine_;}
    float getYOrigine() const { return yOrigine_;}
    float getZOrigine() const { return zOrigine_;}
    float getXNormal() const { return xNormal_;}
    float getYNormal() const { return yNormal_;}
    float getZNormal() const { return zNormal_;}
    float getLongueur() const { return longueur_;}
    float getLargeur() const { return largeur_;}
    QColor getColor() const{ return color_; }
    float getAngleNormal() const { return angleNormal_; }

    void setXOrigine(float xOrigine) { xOrigine_ = xOrigine;}
    void setYOrigine(float yOrigine) { yOrigine_ = yOrigine;}
    void setZOrigine(float zOrigine) { zOrigine_ = zOrigine;}
    void setXNormal(float xNormal) { xNormal_ = xNormal;}
    void setYNormal(float yNormal) { yNormal_ = yNormal;}
    void setZNormal(float zNormal) { zNormal_ = zNormal;}
    void setLongueur(float longueur) { longueur_ = longueur;}
    void setLargeur(float largeur) { largeur_ = largeur;}
};

#endif // SURFACE_H
