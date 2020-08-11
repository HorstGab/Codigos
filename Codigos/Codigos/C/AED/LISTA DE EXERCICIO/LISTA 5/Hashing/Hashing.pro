TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    hashing.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    hashing.h

