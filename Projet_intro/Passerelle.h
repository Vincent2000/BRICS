#ifndef PASSERELLE
#define PASSERELLE
#include"Brique.h"


class Passerelle : public Brique
{
public:
    Passerelle(float x=2, float y=-3, float w=20, float h=5, float d=5);
    void setX(float x) { setX(x); }
    void move(float x, float y, float z);
};


#endif 
