#include "gamescreenwidget.h"
#include<GL/glu.h>
#include<iostream>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 800;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;
const float MAX_DIMENSION     = 50.0f;


/**
 * @brief GameScreenWidget::GameScreenWidget
 * @param parent
 * @author Quentin
 */
GameScreenWidget::GameScreenWidget(QWidget *parent) : QGLWidget(parent)
{
    //Reglage de la taille
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    pause_ = true;
    connect(&m_AnimationTimer, &QTimer::timeout, [&]{
        if (!pause_){
            if(partie_.isFinished()){
                pause_ = true;
                partie_.newGame();
            }
            else {
                partie_.verification();
                partie_.getBall()->move();
            }
        }
        updateGL();
    });

    m_AnimationTimer.setInterval(5);
    m_AnimationTimer.start();
}




/**
 * @brief GameScreenWidget::initializeGL
 * Fonction d'initialisation : appelee lors de la création du widget OpenGL.
 * Elle permet entre autres de définir les differentes options OpenGL ici(la
 * couleur du fond, l'activation ou non de la 3D par exemple)
 * @author Quentin
 */
void GameScreenWidget::initializeGL()
{
    //Reglage de la couleur du fond
    couleurF_.setRgbF(0.0, 0.0, 0.0, 1.0);
    // Réglage de la couleur de fond
    glClearColor(couleurF_.redF(),couleurF_.greenF(),couleurF_.blueF(),couleurF_.alphaF());

    //Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    //ativation de la lumière
    glEnable(GL_LIGHTING);
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 0.0f);
    glEnable(GL_LIGHT0);
    GLfloat directionLamp_tab [] = {1.0f, 1.0f, 1.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, directionLamp_tab);
    GLfloat lamp_tab[] = {1.0, 1.0, 1.0, 100.0};
    //GLfloat a [] = {(GLfloat)0.5, (GLfloat)0.5,(GLfloat)0.5, (GLfloat)1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, lamp_tab);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lamp_tab);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lamp_tab);
}



/**
 * @brief GameScreenWidget::resizeGL
 * @param width
 * @param height
 * @author Quentin
 */
void GameScreenWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0,0,width,height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), 0.0f, 300.0f);
    gluPerspective(68, (double)4/3, 114, 121);
    //glOrtho(0.0, 150.0, 0.0, 200.0, 0.0, 50.0);
    //glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, 2.0f * ORTHO_DIM, 4.0f * ORTHO_DIM);
    //glOrtho(0, 10000, 0, 1000, 0, 10000);
    //glOrtho(0.0, 4.0, 0.0, 4.0, 0.0, 10.0);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



/**
 * @brief GameScreenWidget::paintGL
 * Affichage des briques, de la balle, de la paserelle et de 4 murs
 * @author Quentin et Vincent
 */
void GameScreenWidget::paintGL()
{
    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reinitialisation de la matrice courante
    glLoadIdentity();
    gluLookAt(60, 75, 120, 60, 75, 0, 0, 1, 0);

    glClearColor(couleurF_.redF(),couleurF_.greenF(),couleurF_.blueF(),couleurF_.alphaF());

    //Affichage des briques
    int tailleListe = partie_.getListeBrique().size();
    list<Brique>::iterator it;
    it = partie_.getListeBrique().begin();
    for (int i = 0; i < tailleListe; i++){
        it->appears();
        it++;
    }

    //Affichage de la balle
    partie_.getBall()->appears();

    //Affichage de la passerelle
    partie_.getPasserelle()->appears();

    //Affichage des murs
//    cout<<"Origine = "<< partie_.getWallBot()->getXOrigine()<<", "<< partie_.getWallBot()->getYOrigine()<<", "<< partie_.getWallBot()->getZOrigine()<<endl;
//    cout<<"Normal = "<< partie_.getWallBot()->getXNormal()<<", "<< partie_.getWallBot()->getYNormal()<<", "<< partie_.getWallBot()->getZNormal()<<endl;
//    cout<<"Longeur = "<< partie_.getWallBot()->getLongueur()<<", Largeur = "<< partie_.getWallBot()->getLargeur()<<endl<<endl<<endl;
    partie_.getWallBot()->getSurface()->appear();
    partie_.getWallTop()->getSurface()->appear();
    partie_.getWallLeft()->getSurface()->appear();
    partie_.getWallRight()->getSurface()->appear();
    partie_.getWallBackground()->getSurface()->appear();
//    float xOrigine_ = 120; float yOrigine_ = 0; float zOrigine_ = 0;
//    float xNormal_ = -1; float yNormal_ = 0; float zNormal_ = 0;
//    float longueur_ = 122; float largeur_ = 5;
//    glColor3f(255, 0, 0);
//    glBegin(GL_QUADS);
//    glVertex3f(xOrigine_, yOrigine_, zOrigine_);
//    glVertex3f(xOrigine_ + longueur_ * abs(zNormal_), yOrigine_ + longueur_ * abs(xNormal_), zOrigine_ + longueur_ * abs(yNormal_));
//    glVertex3f(xOrigine_ + longueur_ * abs(zNormal_) + largeur_ * abs(yNormal_), yOrigine_ + longueur_ * abs(xNormal_) + largeur_ * abs(zNormal_), zOrigine_ + longueur_ * abs(yNormal_) + largeur_ * abs(xNormal_));
//    glVertex3f(xOrigine_ + largeur_ * abs(yNormal_), yOrigine_ + largeur_ * abs(zNormal_), zOrigine_ + largeur_ * abs(xNormal_));
//    glEnd();
}



/**
 * @brief GameScreenWidget::keyPressEvent
 * @param event
 * Déplacement de la passerelle avec les flèches de gauche et de droite
 * Déplacement de la balle avec les touches Z, S, Q et D
 * Mise en pause avec la touche espace
 * @author Quentin et Vincent
 */
void GameScreenWidget::keyPressEvent(QKeyEvent *event){

    switch(event->key()){
        //Déplacement de la passerelle gauche, droite
        case Qt::Key_Right:
        {
            if (!pause_) partie_.getPasserelle()->move(3, partie_.getWallLeft(), partie_.getWallRight());
            break;
        }
        case Qt::Key_Left:
        {
            if (!pause_) partie_.getPasserelle()->move(-3, partie_.getWallLeft(), partie_.getWallRight());
            break;
        }
        //Déplacement de la balle z=haut, q=gauche, s=bas, d=droite
        case Qt::Key_Z:
        {
            partie_.getBall()->move(0.0,3.0);
            break;
        }
        case Qt::Key_S:
        {
            partie_.getBall()->move(0.0,-3.0);
            break;
        }
        case Qt::Key_D:
        {
            partie_.getBall()->move(3.0,0.0);
            break;
        }
        case Qt::Key_Q:
        {
            partie_.getBall()->move(-3.0,0.0);
            break;
        }

            // Activation/Arret de la balle
        case Qt::Key_Space:
        {
            pause_=!pause_;
            //                if(m_AnimationTimer.isActive())
            //                    m_AnimationTimer.stop();
            //                else
            //                    m_AnimationTimer.start();
            break;
        }
        case Qt::Key_Plus:
        {
            if(pause_) partie_.getPasserelle()->changeWitdth(1, partie_.getWallBot()->getSurface()->getLargeur());
            break;
        }
        case Qt::Key_Minus:
        {
            if(pause_) partie_.getPasserelle()->changeWitdth(-1, partie_.getWallBot()->getSurface()->getLargeur());
            break;
        }
        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }
    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}
