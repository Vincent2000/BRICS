#ifndef BRIQUE
#define BRIQUE
#include "Ball.h"

class Brique
{
private:
    float X_;//position de l'abscisse
    float Y_;//position de l'ordonn?e
    float Z_;//Position de cote
    float width_;//largeur
    float height_;//hauteur
    float depth_;//profondeur

public:
    Brique(int i, int j, float w = 9.0, float h = 3.0, float d = 5.0);
    ~Brique();
    bool isTouched(Ball* ball);//retrun true if ball touch the brique
    void appears();

    //Setters
    void setX(float x) { X_ = x; }
    void setY(float y) { Y_ = y; }
    void setZ(float z) { Z_ = z; }
    void setWidth(float width){ width_ = width;}
    void setHeight(float height) {height_ = height;}
    void setDepth(float depth){depth_ = depth;}

    //Getter
    float getX() const { return X_;}
    float getY() const{ return Y_;}
    float getZ() const{ return Z_;}
    float getWidth() const{ return width_;}
    float getHeight() const{ return height_;}
    float getDepth() const{ return depth_;}

};

#endif
