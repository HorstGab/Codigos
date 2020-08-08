TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    view/mainwindow.c \
    model/modelarvore.c \
    model/modelmedico.c \
    model/modelarquivo.c \
    model/modelfila.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    view/mainwindow.h \
    model/modelmedico.h \
    model/modelarvore.h \
    model/modelarquivo.h \
    model/modelfila.h

