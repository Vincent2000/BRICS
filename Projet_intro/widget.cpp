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
    ui->text_info->setText("Enter :  réinitialiser le vecteur \nEspace : Lancer la partie \n");
    ui->text_info->setAlignment(Qt::AlignCenter);
    QFont f( "Arial", 10, QFont::Bold);
    ui->text_info->setFont( f);

    ui->nombredepoint->setAlignment(Qt::AlignCenter);
    ui->nombredepoint->setFont( f);

    ui->nombredevie->setAlignment(Qt::AlignCenter);
    ui->nombredevie->setFont( f);

    //Define rectangle to display
    workingRect_=Rect((frameWidth_-subImageWidth_)/3,frameHeight_/3+(frameHeight_/3-subImageHeight_)/3,subImageWidth_,subImageHeight_);
    templateRect_=Rect((workingRect_.width-templateWidth_)/2,(workingRect_.height-templateHeight_)/2,templateWidth_,templateHeight_);
    workingCenter_=Point(workingRect_.x+subImageWidth_/2,workingRect_.y+subImageHeight_/2);

    //initialisation de la caméra
    webCam_ = VideoCapture(0);
    webCam_.set(CV_CAP_PROP_FRAME_WIDTH,frameWidth_);
    webCam_.set(CV_CAP_PROP_FRAME_HEIGHT,frameHeight_);
    if(!webCam_.isOpened())  // check if we succeeded
    {
        cout<<"Error openning the default camera !"<<endl;
    }

    // Get frame1
    webCam_ >> frame1_;

    // Mirror effect
    flip(frame1_,frame1_,1);

    // Extract rect1 and convert to gray
    cvtColor(Mat(frame1_,workingRect_),frameRect1_,COLOR_BGR2GRAY);
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
    ui->nombredevie->setText(QString("Nombre de vies restantes : ")+QString::number(ui->GameScreen->getPartie()->getLife()));
    ui->nombredepoint->setText(QString("Points : ")+QString::number(ui->GameScreen->getPartie()->getNombrePoint()));

    // Create the matchTemplate frame2_ result
    Mat resultImage;    // to store the matchTemplate result
    int result_cols =  frame1_.cols-templateWidth_  + 1;
    int result_rows = frame1_.rows-templateHeight_ + 1;
    resultImage.create( result_cols, result_rows, CV_32FC1 );

    if(webCam_.read(frame2_)){// get a new frame from camera

        // Flip to get a mirror effect
        flip(frame2_,frame2_,1);

        // Invert Blue and Red color channels
        cvtColor(frame2_,frame2_,CV_BGR2RGB);

        cvtColor(Mat(frame2_,workingRect_),frameRect2_,COLOR_BGR2GRAY);

        // Extract template image in frame1
        Mat templateImage(frameRect1_,templateRect_);
        // Do the Matching between the working rect in frame2 and the templateImage in frame1
        matchTemplate( frameRect2_, templateImage, resultImage, TM_CCORR_NORMED );
        // Localize the best match with minMaxLoc
        double minVal; double maxVal; Point minLoc; Point maxLoc;
        minMaxLoc( resultImage, &minVal, &maxVal, &minLoc, &maxLoc);
        // Compute the translation vector between the origin and the matching rect
        Point vect(maxLoc.x-templateRect_.x,maxLoc.y-templateRect_.y);

        // Draw green rectangle and the translation vector
        rectangle(frame2_,workingRect_,Scalar( 0, 255, 0),2);
        Point p(workingCenter_.x+vect.x,workingCenter_.y+vect.y);
        arrowedLine(frame2_,workingCenter_,p,Scalar(255,255,255),2);

        // Si la valeur absolue du vecteur est supérieur a 15 et que la partie n'est pas en pause
        if (abs(p.x-workingCenter_.x)>=15&&!ui->GameScreen->getState()){

            if (p.x-workingCenter_.x>0){
                cout<<p.x-workingCenter_.x<<"Move droite"<<endl;
                ui->GameScreen->getPartie()->getPasserelle()->move(3,ui->GameScreen->getPartie()->getWallLeft(),ui->GameScreen->getPartie()->getWallRight());
            }
            else if(p.x-workingCenter_.x<0){
                cout<<p.x-workingCenter_.x<<"Move left"<<endl;
                ui->GameScreen->getPartie()->getPasserelle()->move(-3,ui->GameScreen->getPartie()->getWallLeft(),ui->GameScreen->getPartie()->getWallRight());
            }
        }
        // Convert to Qt frame2_
        QImage img= QImage((const unsigned char*)(frame2_.data),frame2_.cols,frame2_.rows,QImage::Format_RGB888);
        // Rescale QImage to the size of the CamWidget
        img=img.scaled(QSize(frameWidth_,frameHeight_), Qt::KeepAspectRatio,Qt::FastTransformation);

        // Display on label
        ui->CamView->setPixmap(QPixmap::fromImage(img));
        // Resize the label to fit the frame2_
        ui->CamView->resize(ui->CamView->pixmap()->size());

        // Swap matrixes
        //swap(frameRect1_,frameRect2_);
    }
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
    // Pour calibrer le verteur
    case Qt::Key_Enter:
    {
        // Get frame1
        webCam_ >> frame1_;

        // Mirror effect
        flip(frame1_,frame1_,1);

        // Extract rect1 and convert to gray
        cvtColor(Mat(frame1_,workingRect_),frameRect1_,COLOR_BGR2GRAY);
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
