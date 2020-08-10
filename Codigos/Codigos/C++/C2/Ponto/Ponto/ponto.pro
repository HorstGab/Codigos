TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ponto.cpp \
    circulo.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ponto.h \
    circulo.h

