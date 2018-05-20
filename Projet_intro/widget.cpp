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

/**
 * @brief Widget::~Widget
 * Destruction de ui et de webcam_
 * @author Quentin
 */
Widget::~Widget()
{
    delete ui;
    delete webCam_;
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
