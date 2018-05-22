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
    int subImageWidth_=100;
    int subImageHeight_=100;
    int templateWidth_=25;
    int templateHeight_=25;
    Rect workingRect_;
    Rect templateRect_;
    Point workingCenter_;
    Vector <Rect> motion_Rect_;
    Mat frame1_,frame2_,frameRect1_,frameRect2_;
};

#endif // WIDGET_H
