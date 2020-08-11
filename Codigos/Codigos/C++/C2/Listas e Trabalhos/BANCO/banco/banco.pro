TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    movimentacao.cpp \
    conta.cpp \
    banco.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    movimentacao.h \
    conta.h \
    banco.h

