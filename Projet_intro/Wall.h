#ifndef WALL
#define WALL

#include"Ball.h"
#include"surface.h"
using namespace std;

class Wall//: public Surface
{
    Surface * surface_;

public:
    Wall(float xOrigine, float yOrigine, float zOrigine, float xNormal, float yNormal, float zNormal, float longueur, float largeur, QColor color);
	~Wall();
    void appear();
    Surface * getSurface() {return surface_;}
};

#endif // !WALL
