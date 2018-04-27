#ifndef LISTBRIQUE
#define LISTBRIQUE

#include "Brique.h"
#include "Ball.h"
#include <iterator>
#include <list>
#include "Wall.h"
#include"Passerelle.h"

using namespace std;

class Game {
    Passerelle passerelle_;
    int life_;
    Ball balle_;
    list<Brique> listeBrique_;
    Wall wallRight_;
    Wall wallLeft_;
    Wall wallTop_;
    Wall wallBot_;
public:
    Game();
    ~Game();
	void deleteTouchedBrique(Ball* ball);
	void verification();
	bool isFinished();
	void moveBall(float time);
    list<Brique> getListeBrique() const{return listeBrique_;};
    void setListeBrique(const list<Brique> &listeBrique){listeBrique_ = listeBrique;};
};


#endif
