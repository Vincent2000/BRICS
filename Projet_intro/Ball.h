#ifndef BALL_H
#define BALL_H
#include <cmath>
#include <GL/glu.h>

class Ball
{
    float X_;//position de l'abscisse du centre
    float Y_;//position de l'ordonn?e du centre
    float Z_; //position de la profondeur du centre
    float radius_;//rayon
    //Couleur
    float angle_;// in radians
    float speed_;

public:
    Ball(float x = 0.0f, float y = 0.0f, float z = 0.0f ,float r = 2.5f, float a = 0.0f, float s = 10.0f);
    ~Ball();
    void impactH() { angle_ *= -1; } //change l'angle pour un impact sur un surface horizontale
    void impactV() { angle_ = (float)3.1415 - angle_; } //change l'angle pour un impact sur un surface verticale
    void move(float time) { X_ += time*speed_*cos(radius_); Y_ += time*speed_*sin(radius_); }
    void appears();
    //void move(float )
    //Getters
    float getX() { return X_; }
    float getY() { return Y_; }
    float getRadius() { return radius_; }
    float getAngle() { return angle_; }
    float getSpeed() { return speed_; }
    //Setters
    void setAngle(float a) { angle_ = a; }
};


#endif
