#ifndef BRIQUE
#define BRIQUE
#include "Ball.h"

class Brique
{
    float X_;//position de l'abscisse
    float Y_;//position de l'ordonnée
    float Z_;//Position de cote
    float width_;//largeur
    float height_;//hauteur
    float depth_;//profondeur


public:
    Brique(float x, float y, float w = 9.0, float h = 3.0, float d = 10.0);
	~Brique();
	bool isTouched(Ball* ball);//retrun true if ball touch the brique
    void setX(float x) { X_ = x; }
};

#endif
