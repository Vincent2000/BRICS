#include "widget.h"
#include "ui_widget.h"
#include "opencv2/opencv.hpp"
#include "Game.h"

#include <cstdio>
#include <iostream>

using namespace std;
using namespace cv;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->GameScreen->setPartie(Game());
    webCam_ = new VideoCapture(0);
    webCam_->set(CV_CAP_PROP_FRAME_WIDTH,frameWidth_);
    webCam_->set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight_);
    if(!webCam_->isOpened())  // check if we succeeded
    {
        cout<<"Error openning the default camera !";
    }
    else
    {
        cout<<"Default camera open with success";
    }
}

Widget::~Widget()
{
    delete ui;
    delete webCam_;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Mat image;
    //Define rectangle to display
    Rect workingRect(frameWidth_/3,frameHeight_/3,150,150);
    if(webCam_->read(image)){// get a new frame from camera

        // Flip to get a mirror effect
        flip(image,image,1);

        // Invert Blue and Red color channels
        cvtColor(image,image,CV_BGR2RGB);

        // Draw green rectangle and the translation vector
        rectangle(image,workingRect,Scalar( 0, 255, 0),2);

        // Convert to Qt image
        QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
        // Rescale QImage to the size of the CamWidget
        img=img.scaled(QSize(frameWidth_,frameHeight_), Qt::KeepAspectRatio,Qt::FastTransformation);

        // Display on label
        ui->CamView->setPixmap(QPixmap::fromImage(img));
        // Resize the label to fit the image
        ui->CamView->resize(ui->CamView->pixmap()->size());
    }
}

void Widget::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    // Sortie de l'application
        case Qt::Key_Escape:
        {
            exit(0);
            cout<<"prout"<<endl;
            break;
        }

        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            ui->GameScreen->keyPressEvent(event);
            return;
        }
    }
//    cout<< ui->GameScreen->getPartie().getPasserelle().getX()<<endl;
//    ui->GameScreen->getPartie().getPasserelle().setX(0.0f);
//    cout<< ui->GameScreen->getPartie().getPasserelle().getX()<<endl;
//    ui->GameScreen->getPartie().getPasserelle().setX(ui->GameScreen->getPartie().getPasserelle().getX()+3);
//    cout<< ui->GameScreen->getPartie().getPasserelle().getX()<<endl;
    event->accept();
    update();
}
