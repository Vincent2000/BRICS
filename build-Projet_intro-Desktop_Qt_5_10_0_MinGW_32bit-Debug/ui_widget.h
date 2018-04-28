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
    GameScreenWidget *GameSreen;
    QWidget *CamWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *CamView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1048, 763);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        GameSreen = new GameScreenWidget(Widget);
        GameSreen->setObjectName(QStringLiteral("GameSreen"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameSreen->sizePolicy().hasHeightForWidth());
        GameSreen->setSizePolicy(sizePolicy);
        GameSreen->setMinimumSize(QSize(1030, 381));

        verticalLayout->addWidget(GameSreen);

        CamWidget = new QWidget(Widget);
        CamWidget->setObjectName(QStringLiteral("CamWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CamWidget->sizePolicy().hasHeightForWidth());
        CamWidget->setSizePolicy(sizePolicy1);
        CamWidget->setMinimumSize(QSize(595, 230));
        CamWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(CamWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CamView = new QLabel(CamWidget);
        CamView->setObjectName(QStringLiteral("CamView"));
        sizePolicy1.setHeightForWidth(CamView->sizePolicy().hasHeightForWidth());
        CamView->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(CamView);


        verticalLayout->addWidget(CamWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        CamView->setText(QApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
