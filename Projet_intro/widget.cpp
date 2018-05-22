#include "widget.h"
#include "ui_widget.h"
#include "opencv2/opencv.hpp"
#include "Game.h"

#include <cstdio>
#include <iostream>

using namespace std;
using namespace cv;

/**
 * @brief Widget::Widget
 * @param parent
 * Constructeur de Widget
 * @author Quentin
 */
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->GameScreen->setPartie(Game());
    webCam_ = VideoCapture(0);
    webCam_.set(CV_CAP_PROP_FRAME_WIDTH,frameWidth_);
    webCam_.set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight_);
    if(!webCam_.isOpened())  // check if we succeeded
    {
        cout<<"Error openning the default camera !";
    }
    else
    {
        cout<<"Default camera open with success";
    }
}

/**
 * @brief Widget::~Widget
 * Destruction de ui et de webcam_
 * @author Quentin
 */
Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Widget::paintEvent
 * @param event
 * @author Quentin
 */
void Widget::paintEvent(QPaintEvent *event)
{
    //Mise à jour du nombre de vie
    ui->nombredevie->setText(QString("Nombre de vies restantes : ")+QString::number(ui->GameScreen->getPartie().getLife()));
    ui->nombredepoint->setText(QString("Points : ")+QString::number(ui->GameScreen->getPartie().getNombrePoint()));

    //Definiton des rectangle a afficher
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            Rect workingRect(frameWidth_/3+50*i,frameHeight_/3+50*j,50,50);
            motion_Rect_.push_back(workingRect);
        }
    }

    //Definition de la frame de reference, de celle de comparaison et des templates
    Mat frame1,frame2;
    Vector<Mat> frame1RectVect,frame2RectVect;

    //Capture de la frame de reference
    webCam_ >> frame1;
    //Effet mirroir
    flip(frame1,frame1,1);
    //Extration des rectangles et convertion en gris
    Mat frameRectTemp;
    for (Vector<Rect>::iterator it=motion_Rect_.begin();it!=motion_Rect_.end();it++){
        cvtColor(Mat(frame1,*it),frameRectTemp,COLOR_BGR2GRAY);
        frame1RectVect.push_back(frameRectTemp);
    }

    if(webCam_.read(frame2)){// get a new frame from camera

        // Flip to get a mirror effect
        flip(frame2,frame2,1);

        // Invert Blue and Red color channels
        cvtColor(frame2,frame2,CV_BGR2RGB);

        // Draw green rectangle and the translation vector
        for (Vector<Rect>::iterator it=motion_Rect_.begin();it!=motion_Rect_.end();it++){
            rectangle(frame2,*it,Scalar( 0, 255, 0),2);
        }

        // Convert to Qt frame2
        QImage img= QImage((const unsigned char*)(frame2.data),frame2.cols,frame2.rows,QImage::Format_RGB888);
        // Rescale QImage to the size of the CamWidget
        img=img.scaled(QSize(frameWidth_,frameHeight_), Qt::KeepAspectRatio,Qt::FastTransformation);

        // Display on label
        ui->CamView->setPixmap(QPixmap::fromImage(img));
        // Resize the label to fit the frame2
        ui->CamView->resize(ui->CamView->pixmap()->size());

    }
    event->accept();
}

/**
 * @brief Widget::keyPressEvent
 * @param event
 * @author Quentin
 */
void Widget::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    // Sortie de l'application
    case Qt::Key_Escape:
    {
        close();
        break;
    }

        // Cas par defaut
    default:
    {
        // Ignorer l'evenement
        ui->GameScreen->keyPressEvent(event);
    }
    }
    event->accept();
    update();
}
