#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T21:38:24
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko
TEMPLATE = app


SOURCES += main.cpp\
    startpage.cpp \
    scorepage.cpp \
    menu.cpp \
    musicmemo.cpp

HEADERS  += \
    startpage.h \
    scorepage.h \
    menu.h \
    musicmemo.h

FORMS    += menu.ui \
    startpage.ui \
    scorepage.ui \
    musicmemo.ui

RESOURCES += \
    pic.qrc \
    pic2.qrc \
    music.qrc
