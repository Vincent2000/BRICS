#include "Game.h"
#include "Ball.h"
#include <iostream>

using namespace std;

/*
 * Constructeur de Game
 * Ce que je fais...
 *
 * Inputs :
 *
 * Outputs :
 *
 */
Game::Game()
{
    wallTop_ = Wall(false, 0);
    wallBot_ = Wall(false, 100);
    wallLeft_ = Wall(true, 0);
    wallRight_ = Wall(true, 100);

    //Création de la passerelle
    passerelle_= Passerelle();

    //Initialisation des vies et de la balle sur la passerelle
    life_ = 3;
    balle_ = Ball(passerelle_.getX() + passerelle_.getWidth()/2, 1+passerelle_.getY() + passerelle_.getHeight(), passerelle_.getZ() + passerelle_.getDepth()/2);

    //construction d'une liste de brique
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            listeBrique_.push_back(Brique(i, j));
        }
    }
}

Game::~Game() {
}


void Game::verification() {
        deleteTouchedBrique(balle_);
        passerelle_.isTouched(&balle_);
        if (wallLeft_.isTouched(balle_) || wallRight_.isTouched(balle_)) balle_.impactV();
        if (wallTop_.isTouched(balle_)) balle_.impactH();
        if (wallBot_.isTouched(balle_)) {
            life_-=1;
            balle_.impactV();
        }
}

void Game::deleteTouchedBrique(Ball &ball)
{
    list<Brique>::iterator it;
    for (it = listeBrique_.begin(); it != listeBrique_.end(); it++) {
        if (it->isTouched(&ball)) listeBrique_.erase(it);
    }
}

bool Game::isFinished()
{
/*	if (listeBall.empty()) {
        cout << "Lose";
        return true;
    }
    else
if(listeBrique_.empty())
    {
        cout << "Win";
        return true;
    }
    return false;*/
}

/*
//time in ms
void Game::moveBall(float time) {
    list<Ball>::iterator it;
    for (it = listeBall_.begin(); it != listeBall_.end(); ++it) {
        it->move(time);
    }
};
*/
