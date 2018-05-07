#ifndef BRIQUE
#define BRIQUE
#include "Ball.h"
#include"surface.h"

class Brique
{
private:
    float X_;//position de l'abscisse
    float Y_;//position de l'ordonn?e
    float Z_;//Position de cote
    float width_;//largeur
    float height_;//hauteur
    float depth_;//profondeur

    //Surfaces de la brique. Celle de derrière est absente car elle n'est pas affichée et elle n'est jamais touchée par la balle
    Surface * surfaceTop_;
    Surface * surfaceBot_;
    Surface * surfaceLeft_;
    Surface * surfaceRight_;
    Surface * surfaceForeground_;

public:
    Brique(float x, float y, float w = 9.0, float h = 3.0, float d = 5.0);
    ~Brique();
    bool isTouched(Ball* ball);
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
    Surface *getSurfaceTop() const { return surfaceTop_; }
    Surface *getSurfaceBot() const { return surfaceBot_; }
    Surface *getSurfaceLeft() const { return surfaceLeft_; }
    Surface *getSurfaceRight() const { return surfaceRight_; }
    Surface *getSurfaceForeground() const { return surfaceForeground_; }
};

#endif
