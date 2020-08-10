#ifndef VIEWCONSULTARPESSOA_H
#define VIEWCONSULTARPESSOA_H

#include <QWidget>
#include "model/modelpessoa.h"

namespace Ui {
class ViewConsultarPessoa;
}

class ViewConsultarPessoa : public QWidget
{
    Q_OBJECT

public:
    explicit ViewConsultarPessoa(QWidget *parent = 0);
    ~ViewConsultarPessoa();

private slots:
    void on_pbNovo_clicked();

    void on_pushButton_clicked();

private:
    Ui::ViewConsultarPessoa *ui;

signals:
    void manter (Model *m);
    void consultarTodos();
};

#endif // VIEWCONSULTARPESSOA_H
