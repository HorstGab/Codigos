TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    base.cpp \
    numero.cpp \
    soma.cpp \
    subtracao.cpp \
    lex.cpp \
    multiplicacao.cpp \
    divisao.cpp

HEADERS += \
    base.h \
    numero.h \
    soma.h \
    subtracao.h \
    lex.h \
    multiplicacao.h \
    divisao.h \
    erro.h
