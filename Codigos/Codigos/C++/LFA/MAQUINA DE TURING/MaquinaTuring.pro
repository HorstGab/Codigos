TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    maquinaturing.cpp \
    estado.cpp \
    arquivo.cpp \
    transicao.cpp

include(deployment.pri)

HEADERS += \
    maquinaturing.h \
    estado.h \
    arquivo.h \
    transicao.h

