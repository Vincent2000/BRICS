#ifndef PASSERELLE
#define PASSERELLE
#include"Brique.h"


class Passerelle : public Brique
{
public:
    Passerelle(float x=140, float y=0, float w=20, float h=5, float d=5);
	void setX(float x) { setX(x); };
};


#endif 
