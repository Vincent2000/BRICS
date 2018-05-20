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
    int nombrePoint_;
    Ball balle_;
    list<Brique> listeBrique_;
    Wall * wallRight_;
    Wall * wallLeft_;
    Wall * wallTop_;
    Wall * wallBot_;
    Wall * wallBackground_;
    int colonne_;
    int ligne_;
    float espaceEntreBrique_;
    float depth_;
    float widthBrique_;
    float heightBrique_;

public:
    Game();
    ~Game();
    void deleteTouchedBrique(Ball &ball);
	void verification();
	bool isFinished();
    list<Brique> getListeBrique() const{return listeBrique_;}
    void setListeBrique(const list<Brique> &listeBrique){listeBrique_ = listeBrique;}
    void buildListBrique(float &xPosition, float &yPosition);
    void newGame();

    //Getter
    int getLife() const{ return life_; }
    int getNombrePoint() const{ return nombrePoint_; }
    Ball * getBall() { return &balle_; }
    Passerelle * getPasserelle() { return &passerelle_; }
    Wall * getWallRight() const{ return wallRight_; }
    Wall * getWallLeft() const{ return wallLeft_; }
    Wall * getWallTop() const{ return wallTop_; }
    Wall * getWallBot() const{ return wallBot_; }
    Wall * getWallBackground() const{ return wallBackground_; }

    //Setter
    //void setLife(int life){ life_ = life; }
//    void setBall(Ball b){ balle_ = b; }
//    void setPasserelle(Passerelle p){ passerelle_ = p; }
//    void setWallBackground(Wall *wallBackground){ wallBackground_ = wallBackground; }
//    void setWallBot(Wall *wallBot){ wallBot_ = wallBot; }
//    void setWallTop(Wall *wallTop){ wallTop_ = wallTop; }
//    void setWallLeft(Wall *wallLeft){ wallLeft_ = wallLeft; }
//    void setWallRight(Wall *wallRight){ wallRight_ = wallRight; }

};


#endif
