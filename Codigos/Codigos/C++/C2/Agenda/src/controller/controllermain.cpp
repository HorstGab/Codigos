#include "controllermain.h"

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QMdiSubWindow>
#include <view/viewconsultarpessoa.h>

#include "util/logger.h"
//#include "controller/controllerpessoa.h"


ControllerMain::ControllerMain(int argc, char *argv[])
    : QApplication (argc, argv) {
    qInstallMessageHandler(logHandler);

    mainWindow = new MainWindow();
    connect ( mainWindow, SIGNAL(destroyed()),
              this, SLOT(deleteLater()));
    connect ( mainWindow, SIGNAL(consultarPessoa()),
              this, SLOT(consultarPessoa()));

    mainWindow->show();
}

QMdiSubWindow* ControllerMain::createSubWindow ( QWidget * view ) {
    QMdiSubWindow *subWindow = new QMdiSubWindow(mainWindow);
    subWindow->setWidget( view );

    connect( view, SIGNAL(finished(int)), subWindow, SLOT(close()));
    subWindow->setAttribute(Qt::WA_DeleteOnClose);

    subWindow->setGeometry( view->geometry() );

    return subWindow;
}


void ControllerMain::consultarPessoa() {
    qDebug() << "recebido sinal consultarPessoa";

//    QWidget *w = new ViewConsultarPessoa();
//    mainWindow->addSubWindow(createSubWindow(w));
//    connect ( mainWindow, SIGNAL(destroyed()), w, SLOT(close()) );
    ControllerPessoa *ctrl = new ControllerPessoa();
    QWidget *w = ctrl->getWidget();
    mainWindow->addSubWindow ( createSubWindow( w ) );
    connect ( mainWindow, SIGNAL(destroyed()), w, SLOT(close()) );

}

ControllerMain::~ControllerMain() {
    qDebug() << "Encerrar aplica��o";
    //delete mainWindow;    
    delete Logger::getInstance();
}
