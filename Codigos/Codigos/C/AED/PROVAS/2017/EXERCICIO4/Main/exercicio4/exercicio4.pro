TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    exercicio4.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    exercicio.h

