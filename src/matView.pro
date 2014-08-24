#-------------------------------------------------
#
# Project created by QtCreator 2014-06-26T21:05:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = matView
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matcontentsmodel.cpp

HEADERS  += mainwindow.h \
    matcontentsmodel.h

FORMS    += mainwindow.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += matio
