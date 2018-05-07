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
    int colonne = 10;
    int ligne = 12;
    float espaceEntreBrique = 3;
    float yPosition = 50;
    float depth = 5;
    float xPosition = 0;
    float widthBrique = 9;
    float heightBrique = 3;
    //construction d'une liste de brique
    for (int i = 0; i < colonne; i++) {
        yPosition = 50;
        for (int j = 0; j < ligne; j++) {
            listeBrique_.push_back(Brique(xPosition, yPosition, widthBrique, heightBrique, depth));
            yPosition += espaceEntreBrique + heightBrique;
        }
        xPosition += widthBrique + espaceEntreBrique;
    }
    //Création de la passerelle
    passerelle_= Passerelle((xPosition-10)/2, 0);
    //Initialisation des vies et de la balle sur la passerelle
    life_ = 2;
    balle_ = Ball(passerelle_.getX() + passerelle_.getWidth()/2, 1+passerelle_.getY() + passerelle_.getHeight(), passerelle_.getZ() + passerelle_.getDepth()/2);
    cout<<"yPasserelle = "<<passerelle_.getY()<<endl;
    cout<<"xPosition = "<<xPosition<<endl;
    cout<<"yPosition = "<<yPosition<<endl;
    cout<<"depth = "<<depth<<endl;
    //Constrution des 4 murs
    wallBot_ = new Wall(0, passerelle_.getY(), 0, 0, 1, 0, depth, xPosition);
    wallTop_ = new Wall(0, yPosition, 0, 0, -1, 0, depth, xPosition);
    wallLeft_ = new Wall(0, passerelle_.getY(), 0, 1, 0, 0, yPosition, depth);
    wallRight_ = new Wall(xPosition , passerelle_.getY(), 0, -1, 0, 0, yPosition, depth);

//    cout<<"Origine = "<< wallRight_->getXOrigine()<<", "<< wallRight_->getYOrigine()<<", "<< wallRight_->getZOrigine()<<endl;
//    cout<<"Normal = "<< wallRight_->getXNormal()<<", "<< wallRight_->getYNormal()<<", "<< wallRight_->getZNormal()<<endl;
//    cout<<"Longeur = "<< wallRight_->getLongueur()<<", Largeur = "<< wallRight_->getLargeur()<<endl<<endl<<endl;
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
        balle_ = Ball(passerelle_.getX() + passerelle_.getWidth()/2, 1+passerelle_.getY() + passerelle_.getHeight(), passerelle_.getZ() + passerelle_.getDepth()/2);
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
        if (it->isTouched(&ball)) listeBrique_.erase(it);
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
