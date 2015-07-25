#-------------------------------------------------
#
# Project created by QtCreator 2015-07-17T22:49:20
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = BoardSolve
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    board.cpp \
    cell.cpp \
    a_star.cpp

HEADERS += \
    board.h \
    cell.h \
    moa_global.h \
    nodetree.h \
    a_star.h
