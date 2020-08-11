TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    arvoreb.c \
    fila.c \
    basedados.c \
    arquivoinvertido.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arvoreb.h \
    fila.h \
    basedados.h \
    arquivoinvertido.h

