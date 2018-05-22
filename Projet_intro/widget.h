#ifndef WIDGET_H
#define WIDGET_H

#include "opencv2/opencv.hpp"
#include <QWidget>
#include <Vector>

using namespace cv;
using namespace std;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::Widget *ui;
    VideoCapture webCam_;
    int frameWidth_ = 595;
    int frameHeight_ = 400;
    Vector <Rect> motion_Rect_;
};

#endif // WIDGET_H
