#include "Game.h"
#include <iostream>

using namespace std;

/**
 * @brief Game::Game
 * Construction des briques sur 10 colonnes et 12 lignes
 * Construction de la passerelle placée au centre du jeu
 * Initialisation du nombre de vies restantes à 2
 * Construction de la balle placée juste au-dessus de la passerelle
 * Construction des murs pour délimiter le jeu
 */
Game::Game()
{
    colonne_ = 10;
    ligne_ = 12;
    espaceEntreBrique_ = 3.0f;
    depth_ = 5.0f;
    widthBrique_ = 9.0f;
    heightBrique_ = 3.0f;
//    int yPosition = 80;
//    int xPosition = 0;
//    //construction d'une liste de brique
//    for (int i = 0; i < colonne_; i++) {
//        yPosition = 80;
//        for (int j = 0; j < ligne_; j++) {
//            listeBrique_.push_back(Brique(xPosition, yPosition, widthBrique_, heightBrique_, depth_, QColor(180, 180, 180, 255)));
//            yPosition += espaceEntreBrique_ + heightBrique_;
//        }
//        xPosition += widthBrique_ + espaceEntreBrique_;
//    }
//    xPosition += espaceEntreBrique;
    float xPosition;
    float yPosition;
    buildListBrique(xPosition, yPosition);
    //Création de la passerelle
    passerelle_ = Passerelle((xPosition-10)/2, 0, 20, 5, 5, QColor(255, 140, 0, 255));
    //Initialisation des vies, du nombre de point et de la balle sur la passerelle
    life_ = 2;
    nombrePoint_ = 0;
    balle_ = Ball(passerelle_.getX() + passerelle_.getWidth()/2, 1+passerelle_.getY() + passerelle_.getHeight(), passerelle_.getZ() + passerelle_.getDepth()/2, 2.5f, -3.14159f/2.0f, 2.0f);

    //Constrution des 4 murs
    wallBot_ = new Wall(-espaceEntreBrique_, passerelle_.getY(), 0, 0, 1, 0, depth_, xPosition, QColor(100, 200, 0, 255));
    wallTop_ = new Wall(-espaceEntreBrique_, yPosition, 0, 0, -1, 0, depth_, xPosition, QColor(0, 115, 255, 255));
    wallLeft_ = new Wall(-espaceEntreBrique_, passerelle_.getY(), 0, 1, 0, 0, yPosition, depth_, QColor(0, 115, 255, 255));
    wallRight_ = new Wall(xPosition - espaceEntreBrique_, passerelle_.getY(), 0, -1, 0, 0, yPosition, depth_, QColor(0, 115, 255, 255));
    wallBackground_ = new Wall(- espaceEntreBrique_, passerelle_.getY(), 0, 0, 0, 1, xPosition, yPosition, QColor(255, 255, 255, 255));

}


/**
 * @brief Game::~Game
 */
Game::~Game() {
//    delete wallBot_;
//    delete wallLeft_;
//    delete wallRight_;
//    delete wallTop_;
}



/**
 * @brief Game::verification
 * Suppression des briques touchées
 * Déviation de la balle quand une brique, la passerelle ou un mur est touché
 * Si le mur du bas est touchée, alors décrémentation du nombre de vies restante et repositionnement de la balle juste au-dessus de la passerelle
 */
void Game::verification() {
    deleteTouchedBrique(balle_);
    passerelle_.isTouched(&balle_);
    if (wallLeft_->getSurface()->isTouched(&balle_) || wallRight_->getSurface()->isTouched(&balle_)) balle_.impactV();
    if (wallTop_->getSurface()->isTouched(&balle_)) balle_.impactH();
    if (wallBot_->getSurface()->isTouched(&balle_)) {
        life_ -= 1;
        balle_ = Ball(passerelle_.getX() + passerelle_.getWidth()/2, 1+passerelle_.getY() + passerelle_.getHeight(), passerelle_.getZ() + passerelle_.getDepth()/2, 2.5f, -3.14159f/2.0f, balle_.getSpeed());
    }
}



/**
 * @brief Game::deleteTouchedBrique
 * @param ball
 * Parcours de la liste de briques
 * Si une brique est touchée, alors elle est supprimée
 */
void Game::deleteTouchedBrique(Ball &ball)
{
    list<Brique>::iterator it;
    for (it = listeBrique_.begin(); it != listeBrique_.end(); it++) {
        if (it->isTouched(&ball)) {
            listeBrique_.erase(it);
            nombrePoint_ += 1;
        }
    }
}



/**
 * @brief Game::isFinished
 * Détermine si la parie est terminée
 * @return vrai si le joueur n'a plus de vie ou il n'y a plus de brique
 */
bool Game::isFinished()
{
    return life_ < 0 || listeBrique_.empty();
}

void Game::buildListBrique(float &xPosition, float &yPosition) {
    listeBrique_.clear();
    xPosition = 0;
    for (int i = 0; i < colonne_; i++) {
        yPosition = 80;
        for (int j = 0; j < ligne_; j++) {
            listeBrique_.push_back(Brique(xPosition, yPosition, widthBrique_, heightBrique_, depth_, QColor(180, 180, 180, 255)));
            yPosition += espaceEntreBrique_ + heightBrique_;
        }
        xPosition += widthBrique_ + espaceEntreBrique_;
    }
    xPosition += espaceEntreBrique_;
}

/**
 * @brief Game::newGame
 * Réinitialisation le nombre de vie et la liste de briques
 * Augmentation de la vitese de la balle
 */
void Game::newGame(){
    life_ = 3;
    balle_.upSpeed(0.75);
    float a = 0;
    float b = 0;
    buildListBrique(a, b);
}
