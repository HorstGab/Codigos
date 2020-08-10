TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    playlist.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    main.h \
    playlist.h

