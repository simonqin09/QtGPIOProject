#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T15:51:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helloworldUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GPIOSet.cpp

HEADERS  += mainwindow.h \
    GPIOSet.h

FORMS    += mainwindow.ui

# deployment on Linux
unix {
   target.path = /usr/bin/
   INSTALLS += target \
} 
