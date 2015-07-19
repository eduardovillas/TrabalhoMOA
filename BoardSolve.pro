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
    relationshipbuilder.cpp \
    watcherstatisticgame.cpp

HEADERS += \
    board.h \
    cell.h \
    moa_global.h \
    relationshipbuilder.h \
    watcherstatisticgame.h
