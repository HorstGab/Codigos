TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Btree.c \
    menus.c \
    queue.c \
    entrymanipulation.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Btree.h \
    menus.h \
    queue.h \
    entrymanipulation.h

