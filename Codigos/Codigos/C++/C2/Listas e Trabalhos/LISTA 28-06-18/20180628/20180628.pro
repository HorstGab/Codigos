TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    data.cpp \
    pessoa.cpp \
    agenda.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    data.h \
    pessoa.h \
    agenda.h

