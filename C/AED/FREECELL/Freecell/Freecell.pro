TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    start.c \
    comandos.c \
    pilhas.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    main.h \
    start.h \
    comandos.h \
    pilhas.h

