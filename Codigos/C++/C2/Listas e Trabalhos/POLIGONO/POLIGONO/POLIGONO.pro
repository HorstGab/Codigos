TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    poligono.cpp \
    circulo.cpp \
    retangulo.cpp \
    triangulo.cpp \
    poligonocomplexo.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    poligono.h \
    circulo.h \
    retangulo.h \
    triangulo.h \
    poligonocomplexo.h

