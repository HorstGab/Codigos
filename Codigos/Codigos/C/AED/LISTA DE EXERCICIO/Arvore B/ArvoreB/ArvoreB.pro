TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    arvoreb.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arvoreb.h

