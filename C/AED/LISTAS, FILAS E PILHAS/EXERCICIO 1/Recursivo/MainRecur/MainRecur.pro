TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    recursiva.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    exerc1_rec.h

