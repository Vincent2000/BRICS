#include "gamescreenwidget.h"


// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 800;
const float ASPECT_RATIO      = static_cast<float>(WIN_WIDTH) / WIN_HEIGHT;
const float ORTHO_DIM         = 50.0f;

// Constructeur
GameScreenWidget::GameScreenWidget(QWidget *parent) : QGLWidget(parent)
{
    //Reglage de la taille
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
}

// Fonction d'initialisation : appelee lors de la création du widget OpenGL.
// Elle permet entre autres de définir les differentes options OpenGL ici(la
// couleur du fond, l'activation ou non de la 3D par exemple)
void GameScreenWidget::initializeGL()
{
    //Reglage de la couleur du fond
    couleurF_.setRgbF(0.0,0.0,0.0,1.0);
}

void GameScreenWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0,0,width,height);
    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ORTHO_DIM * ASPECT_RATIO, ORTHO_DIM * ASPECT_RATIO, -ORTHO_DIM, ORTHO_DIM, -2.0f * ORTHO_DIM, 2.0f * ORTHO_DIM);

    // Definition de la matrice de modele
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GameScreenWidget::paintGL()
{
    // Reinitialisation du tampon de couleur
    glClear(GL_COLOR_BUFFER_BIT);

    // On fixe la couleur du Fond
    glClearColor(couleurF_.redF(),couleurF_.greenF(),couleurF_.blueF(),couleurF_.alphaF());

    // Reinitialisation de la matrice courante
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    list<Brique>::iterator it;
    for (it=partie_.getListeBrique().begin();it!=partie_.getListeBrique().end();it++){

    }

}

//Getters and Setters
Game GameScreenWidget::getPartie() const
{
    return partie_;
}

void GameScreenWidget::setPartie(const Game &partie)
{
    partie_ = partie;
}
