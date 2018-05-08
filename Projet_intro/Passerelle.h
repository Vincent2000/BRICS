#ifndef PASSERELLE
#define PASSERELLE
#include"Brique.h"
#include"Wall.h"


class Passerelle : public Brique
{
public:
    Passerelle(float x=0, float y=0, float w=20, float h=5, float d=5, QColor color = QColor(255, 140, 0, 255));
    void move(float x, Wall * wallLeft, Wall * wallRight);
    bool isTouched(Ball *ball);
};


#endif 
