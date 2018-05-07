#-------------------------------------------------
#
# Project created by QtCreator 2018-03-07T14:35:02
#
#-------------------------------------------------

QT       += core gui opengl widgets

TEMPLATE = app

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}

TARGET = Projet_intro
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
# DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
        widget.cpp \
    gamescreenwidget.cpp \
    Ball.cpp \
    game.cpp \
    Brique.cpp \
    passerelle.cpp \
    wall.cpp \
    surface.cpp

HEADERS += widget.h \
    gamescreenwidget.h \
    Brique.h \
    Game.h \
    Passerelle.h \
    Wall.h \
    Ball.h \
    surface.h

FORMS += widget.ui

INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include

LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413 \
    -lopencv_video2413 \
    -lopencv_features2d2413 \
    -lopencv_calib3d2413
