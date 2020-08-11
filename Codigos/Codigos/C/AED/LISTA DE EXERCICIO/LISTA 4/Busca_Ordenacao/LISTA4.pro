TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Busca_Ord.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    busca_ord.h

