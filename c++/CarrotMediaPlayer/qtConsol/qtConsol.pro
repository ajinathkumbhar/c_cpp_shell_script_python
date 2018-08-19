#-------------------------------------------------
#
# Project created by QtCreator 2018-08-19T15:53:29
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = qtConsol
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ../CarrotMediaPlayer.cpp \
    ../cPlay.cpp

HEADERS += \
    ../CarrotMediaPlayer.h \

INCLUDEPATH += \
    /usr/include/gstreamer-1.0 \
    /usr/include/glib-2.0 \
    /usr/lib/x86_64-linux-gnu/glib-2.0/include \

PKGCONFIG += gstreamer-1.0 glib-2.0 gobject-2.0 gstreamer-app-1.0 gstreamer-pbutils-1.0
