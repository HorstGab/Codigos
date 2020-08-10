#-------------------------------------------------
#
# Project created by QtCreator 2018-08-09T13:59:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

greaterThan(QT_MAJOR_VERSION, 5): RC_ICONS += ./resource/SCA.ico
#win32:RC_FILE += ./resource/sca.rc           #for qt 5-

TARGET = Agenda
TEMPLATE = app


SOURCES += main.cpp\
        view/mainwindow.cpp \
    util/logger.cpp \
    controller/controllermain.cpp \
    dao/dao.cpp \
    view/viewconsultarpessoa.cpp \
    model/modelpessoa.cpp \
    view/viewmanterpessoa.cpp \
    controller/controllerpessoa.cpp \
    dao/daopessoa.cpp

HEADERS  += view/mainwindow.h \
    util/logger.h \
    controller/controllermain.h \
    model/model.h \
    dao/dao.h \
    model/modelpessoa.h \
    view/viewconsultarpessoa.h \
    view/viewmanterpessoa.h \
    controller/controllerpessoa.h \
    view/viewtreewidgetitem.h \
    dao/daopessoa.h

FORMS    += view/mainwindow.ui \
    view/viewconsultarpessoa.ui \
    view/viewmanterpessoa.ui

RESOURCES += \
    resource/resource.qrc
