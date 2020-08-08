#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSubWindow( QMdiSubWindow* subWindow){
    this->ui->mdiArea->addSubWindow(subWindow);
    subWindow->showNormal();
}

void MainWindow::on_actionConsultar_triggered()
{
    emit consultarPessoa();
    qDebug()<< "Consultar pessoa";
}

void MainWindow::on_actionFechar_triggered()
{
    close();
}

void MainWindow::on_actionLado_a_Lado_triggered()
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actionCascata_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}
