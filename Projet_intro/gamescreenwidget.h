#ifndef GAMESCREENWIDGET_H
#define GAMESCREENWIDGET_H

#include <QtOpenGL>
#include <QGLWidget>
#include <QColor>
#include <QTimer>
#include "Game.h"

class GameScreenWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GameScreenWidget(QWidget *parent = nullptr);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    Game getPartie() const{ return partie_; }
    void setPartie(const Game &partie){ partie_ = partie;}
    void keyPressEvent(QKeyEvent *event);
    bool getState(){return pause_;}

signals:

public slots:

private :
    //Timer d'animation
    float m_TimeElapsed = 0.0f;
    QTimer m_AnimationTimer;
    QColor couleurF_;
    Game partie_;
    bool pause_;
};

#endif // GAMESCREENWIDGET_H
