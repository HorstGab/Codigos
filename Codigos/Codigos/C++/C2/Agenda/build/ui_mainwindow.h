/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConsultar;
    QAction *actionFechar;
    QAction *actionLado_a_Lado;
    QAction *actionCascata;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuAgenda;
    QMenu *menuJanela;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(409, 306);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SCA.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionConsultar = new QAction(MainWindow);
        actionConsultar->setObjectName(QStringLiteral("actionConsultar"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/groups.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionConsultar->setIcon(icon1);
        actionFechar = new QAction(MainWindow);
        actionFechar->setObjectName(QStringLiteral("actionFechar"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/fechar.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actionFechar->setIcon(icon2);
        actionLado_a_Lado = new QAction(MainWindow);
        actionLado_a_Lado->setObjectName(QStringLiteral("actionLado_a_Lado"));
        actionCascata = new QAction(MainWindow);
        actionCascata->setObjectName(QStringLiteral("actionCascata"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        verticalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 409, 20));
        menuAgenda = new QMenu(menuBar);
        menuAgenda->setObjectName(QStringLiteral("menuAgenda"));
        menuJanela = new QMenu(menuBar);
        menuJanela->setObjectName(QStringLiteral("menuJanela"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QStringLiteral("toolBar_3"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);

        menuBar->addAction(menuAgenda->menuAction());
        menuBar->addAction(menuJanela->menuAction());
        menuAgenda->addAction(actionConsultar);
        menuAgenda->addSeparator();
        menuAgenda->addAction(actionFechar);
        menuJanela->addAction(actionLado_a_Lado);
        menuJanela->addAction(actionCascata);
        toolBar->addAction(actionConsultar);
        toolBar_2->addAction(actionFechar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Agenda", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "Sistema de Controle de Agenda", 0));
#endif // QT_NO_TOOLTIP
        actionConsultar->setText(QApplication::translate("MainWindow", "Consultar", 0));
#ifndef QT_NO_TOOLTIP
        actionConsultar->setToolTip(QApplication::translate("MainWindow", "Consultar usu\303\241rios cadastrados", 0));
#endif // QT_NO_TOOLTIP
        actionConsultar->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        actionFechar->setText(QApplication::translate("MainWindow", "Fechar", 0));
#ifndef QT_NO_TOOLTIP
        actionFechar->setToolTip(QApplication::translate("MainWindow", "Fechar a aplica\303\247\303\243o", 0));
#endif // QT_NO_TOOLTIP
        actionLado_a_Lado->setText(QApplication::translate("MainWindow", "Lado a Lado", 0));
        actionCascata->setText(QApplication::translate("MainWindow", "Cascata", 0));
        menuAgenda->setTitle(QApplication::translate("MainWindow", "Agenda", 0));
        menuJanela->setTitle(QApplication::translate("MainWindow", "Janela", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
        toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
