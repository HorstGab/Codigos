TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    arvore_binaria.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arvore_binaria.h

