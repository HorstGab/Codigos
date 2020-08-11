#ifndef CONTROLLERMAIN_H
#define CONTROLLERMAIN_H

#include <QString>
#include <QObject>
#include <QApplication>
#include <QMdiSubWindow>

#include "view/mainwindow.h"
#include "controller/controllerpessoa.h"

class ControllerMain : public QApplication {
    Q_OBJECT
private:
    MainWindow *mainWindow;

    QMdiSubWindow *createSubWindow( QWidget * view );
public:
    ControllerMain(int argc, char *argv[]);

    ~ControllerMain();

public slots:
   void consultarPessoa();
};

#endif // CONTROLLERMAIN_H
