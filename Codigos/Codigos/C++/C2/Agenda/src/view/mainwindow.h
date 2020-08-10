#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void addSubWindow(QMdiSubWindow* subWindow);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

signals:
    void consultarPessoa();
private slots:
    void on_actionConsultar_triggered();
    void on_actionFechar_triggered();
    void on_actionLado_a_Lado_triggered();
    void on_actionCascata_triggered();
};

#endif // MAINWINDOW_H
