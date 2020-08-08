TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    exercicio1.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    exercicio1.h

