#ifndef LISTBRIQUE
#define LISTBRIQUE

#include "Brique.h"
#include "Ball.h"
#include <iterator>
#include <list>
#include "Wall.h"
#include "Passerelle.h"

using namespace std;

class Game {
    Passerelle passerelle_;
    int life_;
    Ball balle_;
    list<Brique> listeBrique_;
    Wall *wallRight_;
    Wall *wallLeft_;
    Wall *wallTop_;
    Wall *wallBot_;
    Wall *wallBackground_;

public:
    Game();
    ~Game();
    void deleteTouchedBrique(Ball &ball);
	void verification();
	bool isFinished();
    //void moveBall(float time);
    list<Brique> getListeBrique() const{return listeBrique_;}
    void setListeBrique(const list<Brique> &listeBrique){listeBrique_ = listeBrique;}
    //Getter
    int getLife() {return life_;}
    Ball* getBall(){return &balle_;}
    Passerelle* getPasserelle(){ return &passerelle_; }
    Wall *getWallRight() const{ return wallRight_; }
    Wall *getWallLeft() const{ return wallLeft_; }
    Wall *getWallTop() const{ return wallTop_; }
    Wall *getWallBot() const{ return wallBot_; }
    Wall *getWallBackground() const{ return wallBackground_; }
};


#endif
