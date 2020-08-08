TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    knapsack.c \
    mult_matrizes.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    knapsack.h \
    mult_matrizes.h

