#include "Passerelle.h"
Passerelle::Passerelle(float x, float y, float w, float h, float d) : Brique(x, y, w, h, d){

}

void Passerelle::move(float x, float y, float z){
    setX(getX() + x);
    setY(getY() + y);
    setZ(getZ() + z);
}
