/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "gamescreenwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    GameScreenWidget *GameScreen;
    QHBoxLayout *horizontalLayout_2;
    QWidget *CamWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *CamView;
    QLabel *nombredepoint;
    QLabel *nombredevie;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1048, 991);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        GameScreen = new GameScreenWidget(Widget);
        GameScreen->setObjectName(QStringLiteral("GameScreen"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameScreen->sizePolicy().hasHeightForWidth());
        GameScreen->setSizePolicy(sizePolicy);
        GameScreen->setMinimumSize(QSize(1030, 600));

        verticalLayout->addWidget(GameScreen);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        CamWidget = new QWidget(Widget);
        CamWidget->setObjectName(QStringLiteral("CamWidget"));
        sizePolicy.setHeightForWidth(CamWidget->sizePolicy().hasHeightForWidth());
        CamWidget->setSizePolicy(sizePolicy);
        CamWidget->setMinimumSize(QSize(595, 300));
        CamWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(CamWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CamView = new QLabel(CamWidget);
        CamView->setObjectName(QStringLiteral("CamView"));
        sizePolicy.setHeightForWidth(CamView->sizePolicy().hasHeightForWidth());
        CamView->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(CamView);


        horizontalLayout_2->addWidget(CamWidget);

        nombredepoint = new QLabel(Widget);
        nombredepoint->setObjectName(QStringLiteral("nombredepoint"));

        horizontalLayout_2->addWidget(nombredepoint);

        nombredevie = new QLabel(Widget);
        nombredevie->setObjectName(QStringLiteral("nombredevie"));

        horizontalLayout_2->addWidget(nombredevie);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        CamView->setText(QApplication::translate("Widget", "TextLabel", nullptr));
        nombredepoint->setText(QApplication::translate("Widget", "TextLabel", nullptr));
        nombredevie->setText(QApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
