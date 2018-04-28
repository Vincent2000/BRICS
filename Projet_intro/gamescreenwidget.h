#ifndef GAMESCREENWIDGET_H
#define GAMESCREENWIDGET_H

#include <QtOpenGL>
#include <QGLWidget>
#include <QColor>
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

signals:

public slots:

private :
    QColor couleurF_;
    Game partie_;
};

#endif // GAMESCREENWIDGET_H
