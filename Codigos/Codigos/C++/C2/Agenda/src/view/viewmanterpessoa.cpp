#include "viewmanterpessoa.h"
#include "ui_viewmanterpessoa.h"

ViewManterPessoa::ViewManterPessoa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewManterPessoa)
{
    ui->setupUi(this);
}

ViewManterPessoa::~ViewManterPessoa()
{
    delete ui;
}

void ViewManterPessoa::manter(Model *m)
{
    ModelPessoa *p = (ModelPessoa*)m;
    //exibir os dados na Interface grafica


    ui->pbExcluir->setEnabled(p->getIdPessoa() != -1);

    ui->idPessoa->setText(QString::number(p->getIdPessoa()));

    ui->cpf->setText(p->getCpf());
    ui->dtNascimento->setDate(p->getDtNascimento());
    ui->nome->setText(p->getNome());
    ui->SexoFeminino->setChecked(p->getSexo() == 'F');
    ui->SexoMasculino->setChecked(p->getSexo() == 'M');

    showNormal();
}

void ViewManterPessoa::on_pbCancelar_clicked()
{
    hide();
}
