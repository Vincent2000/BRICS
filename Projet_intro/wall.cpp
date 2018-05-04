#include "Wall.h"

/*
* Constructeur de Wall
* initialise vertical_ par v et position_ par p
*
* Inputs : 
*	v est un bool�en qui indique si le mur est vertical (true) ou non (false)
*	g est un bool�en qui indique si le mur est � gauche (ou en-haut) (true) ou � droite (ou en-bas) (false)
*	p est la position du mur
*
*/
Wall::Wall(bool v, bool g_h, float p)
{
    vertical_ = v;
	gaucheOuHaut_ = g_h;
    position_ = p;
}

/*
* D�onstructeur de Wall
* Rien
*
* Inputs :
*
* Outputs :
*
*/
Wall::~Wall()
{
}

/*
* Constructeur de Game
*	1 - Condition pour savoir si le mur est vertical ou horizontal
*	2 - Condition pour savoir si 
* Inputs : 
*	ball de type Ball 
* Outputs :
*	Retourne vrai si le mur est touch� par la balle et faux sinon
*
*/
bool Wall::isTouched(Ball ball) {
    if (vertical_ && gaucheOuHaut_) {
        if(ball.getX() - ball.getRadius() <= position_) return true;
        return false;
    }

	if (vertical_ && !gaucheOuHaut_) {
		if (ball.getX() + ball.getRadius() >= position_) return true;
		return false;
	}

	if (!vertical_ && gaucheOuHaut_){
		if (ball.getY() + ball.getRadius() >= position_) return true;
		return false;
	}

    if (!vertical_ && !gaucheOuHaut_) {
        if(ball.getX() - ball.getRadius() <= position_) return true;
        return false;
    }
}
