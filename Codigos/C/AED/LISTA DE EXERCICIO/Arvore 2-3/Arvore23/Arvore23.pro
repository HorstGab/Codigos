TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    arvore23.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arvore23.h

