#include "gamescreenwidget.h"
#include<GL/glu.h>
#include<iostream>

// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 800;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;
const float MAX_DIMENSION     = 50.0f;

// Constructeur
GameScreenWidget::GameScreenWidget(QWidget *parent) : QGLWidget(parent)
{
    //Reglage de la taille
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    connect(&m_AnimationTimer,&QTimer::timeout,[&]{
        partie_.verification();
        partie_.getBall()->move();
        updateGL();
    });

    m_AnimationTimer.setInterval(100);
    m_AnimationTimer.start();
}

// Fonction d'initialisation : appelee lors de la création du widget OpenGL.
// Elle permet entre autres de définir les differentes options OpenGL ici(la
// couleur du fond, l'activation ou non de la 3D par exemple)
void GameScreenWidget::initializeGL()
{
    //Reglage de la couleur du fond
    couleurF_.setRgbF(0.0, 0.0, 0.0, 1.0);
    // Réglage de la couleur de fond
    glClearColor(couleurF_.redF(),couleurF_.greenF(),couleurF_.blueF(),couleurF_.alphaF());

    //Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
}

void GameScreenWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0,0,width,height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), 0.0f, 300.0f);
    gluPerspective(100, (double)4/3, 55, 100);
    //glOrtho(0.0, 150.0, 0.0, 200.0, 0.0, 50.0);
    //glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, 2.0f * ORTHO_DIM, 4.0f * ORTHO_DIM);
    //glOrtho(0, 10000, 0, 1000, 0, 10000);
    //glOrtho(0.0, 4.0, 0.0, 4.0, 0.0, 10.0);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GameScreenWidget::paintGL()
{
    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reinitialisation de la matrice courante
    glLoadIdentity();
    gluLookAt(60, 40, 80, 60, 40, 0, 0, 1, 0);

    glClearColor(couleurF_.redF(),couleurF_.greenF(),couleurF_.blueF(),couleurF_.alphaF());

    //    Dessin des briques
    int tailleListe = partie_.getListeBrique().size();
    list<Brique>::iterator it;
    it = partie_.getListeBrique().begin();
    for (int i = 0; i < tailleListe; i++){
        it->appears();
        it++;
    }

    //Dessin de la balle
    partie_.getBall()->appears();

    //Dessin de la passerelle
    partie_.getPasserelle()->appears();

    if (isMoving_){}
    //    cout<<partie_.getPasserelle().getX()<<endl;
    //    for (it = partie_.getListeBrique().begin(); it != partie_.getListeBrique().end(); it++){
    //        it->appears();
    //    }
}

void GameScreenWidget::keyPressEvent(QKeyEvent *event){

    switch(event->key()){
    //Déplacement de la passerelle gauche, droite
    case Qt::Key_Right:
    {
        partie_.getPasserelle()->move(3, 0, 0);
        break;
    }
    case Qt::Key_Left:
    {
        partie_.getPasserelle()->move(-3, 0, 0);
        break;
    }

        //Déplacement de la balle z=haut, q=gauche, s=bas, d=droite
    case Qt::Key_Z:
    {
        //cout<<partie_.getPasserelle().getX()<<endl;
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
        isMoving_=!isMoving_;
        //                if(m_AnimationTimer.isActive())
        //                    m_AnimationTimer.stop();
        //                else
        //                    m_AnimationTimer.start();

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

    //        Passerelle p = Passerelle();
    //        cout<<p.getX()<<endl;
    //        p.X_+=3;
    //        cout<<p.getX()+3<<endl;

    //        cout<<partie_.getPasserelle().getX()<<endl;
    //        partie_.getPasserelle().setX(partie_.getPasserelle().getX()+3);
    //        cout<<partie_.getPasserelle().getX()<<endl;
    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}
