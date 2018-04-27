#ifndef WIDGET_H
#define WIDGET_H

#include "opencv2/opencv.hpp"
#include <QWidget>

using namespace cv;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    void paintEvent(QPaintEvent *event);
    VideoCapture * webCam_;
    int frameWidth_ =595;
    int frameHeight_ =230;
};

#endif // WIDGET_H
