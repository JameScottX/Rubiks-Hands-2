78b#-------------------------------------------------
#
# Project created by QtCreator 2018-01-10T22:40:42
#
#-------------------------------------------------

QT       += core gui
QT       += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = magicCube
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        magic.cpp \
      colorhandle.cpp \
    core.cpp \
    serial.cpp \
    cameraset.cpp \
    stepopt.cpp

HEADERS += \
        magic.h \
    colorhandle.h \
    core.h \
    serial.h \
    cameraset.h \
    stepopt.h \

FORMS += \
    cameraset.ui \
    magic.ui

INCLUDEPATH+=C:/OpenCV/opencv/build/include  \
             C:/OpenCV/opencv/build/include/opencv2 \
             D:/File_My/Rubiks-Hand2/magicCube-Opt-kociemba/kociemba/include

LIBS+= C:/OpenCV/opencv/build/x64/vc15/lib/opencv_world400.lib
LIBS+= C:/OpenCV/opencv/build/x64/vc15/lib/opencv_world400d.lib
LIBS+= D:/File_My/Rubiks-Hand2/magicCube-Opt-kociemba/kociemba/kociemba.lib

VERSION = 1.0
RC_ICONS = a9.ico

