#ifndef PASSERELLE
#define PASSERELLE
#include"Brique.h"


class Passerelle : public Brique
{
public:
    Passerelle(float x=2, float y=-10, float w=20, float h=5, float d=5);
    void move(float x, float y, float z);
};


#endif 
