TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    elevador.cpp \
    lampada.cpp \
    lampadatresestados.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    elevador.h \
    lampada.h \
    lampadatresestados.h

