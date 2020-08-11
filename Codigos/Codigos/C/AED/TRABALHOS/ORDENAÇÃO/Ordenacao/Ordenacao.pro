TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    sort.c \
    clocksort.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sort.h \
    main.h \
    clocksort.h

