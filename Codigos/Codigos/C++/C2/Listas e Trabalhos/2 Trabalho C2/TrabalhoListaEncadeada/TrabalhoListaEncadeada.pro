TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    listasimples.cpp \
    pilha.cpp \
    fila.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    listasimples.h \
    pilha.h \
    fila.h

