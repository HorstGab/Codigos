#ifndef VIEWMANTERPESSOA_H
#define VIEWMANTERPESSOA_H

#include <QWidget>
#include "model/modelpessoa.h"

namespace Ui {
class ViewManterPessoa;
}

class ViewManterPessoa : public QWidget
{
    Q_OBJECT

public:
    explicit ViewManterPessoa(QWidget *parent = 0);
    ~ViewManterPessoa();

private:
    Ui::ViewManterPessoa *ui;

public slots:
    void manter (Model *m);
private slots:
    void on_pbCancelar_clicked();
};

#endif // VIEWMANTERPESSOA_H
