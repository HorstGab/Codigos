QT += core
QT -= gui

CONFIG += c++11

TARGET = AVL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    avl.cpp \
    logger.cpp

HEADERS += \
    avl.h \
    logger.h
