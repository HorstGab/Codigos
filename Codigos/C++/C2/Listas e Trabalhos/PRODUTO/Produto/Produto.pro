TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    produto.cpp \
    quimico.cpp \
    usaproduto.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    produto.h \
    quimico.h \
    usaproduto.h

