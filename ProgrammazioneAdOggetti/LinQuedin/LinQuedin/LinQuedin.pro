#-------------------------------------------------
#
# Project created by QtCreator 2015-08-27T15:11:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinQuedin
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    username.cpp \
    info.cpp \
    rete.cpp \
    utente.cpp \
    db.cpp \
    win_registration.cpp \
    win_view.cpp \
    win_admin.cpp \
    win_user.cpp

HEADERS  += mainwindow.h \
    username.h \
    info.h \
    rete.h \
    utente.h \
    db.h \
    win_registration.h \
    win_view.h \
    win_admin.h \
    win_user.h

FORMS    += mainwindow.ui
