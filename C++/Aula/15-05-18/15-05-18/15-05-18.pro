TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pilha.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    pilha.h

