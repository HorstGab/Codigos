TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    arquivo.cpp \
    automatos.cpp \
    estados.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arquivo.h \
    automatos.h \
    estados.h

