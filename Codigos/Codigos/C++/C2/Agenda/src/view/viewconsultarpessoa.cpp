#include "viewconsultarpessoa.h"
#include "ui_viewconsultarpessoa.h"
#include "view/viewtreewidgetitem.h"

ViewConsultarPessoa::ViewConsultarPessoa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewConsultarPessoa)
{
    ui->setupUi(this);
}

ViewConsultarPessoa::~ViewConsultarPessoa()
{
    delete ui;
}


void ViewConsultarPessoa::on_pbNovo_clicked()
{
//    emit manter(new ModelPessoa());

    ModelPessoa p;

    p.setCpf("102.526.412-00");
    p.setNome("Gabriel Horst Montoanelli");
    p.setIdPessoa(1);
    p.setDtNascimento(QDate::currentDate());
    p.setSexo('M');

    emit manter(&p);
}

void ViewConsultarPessoa::on_pushButton_clicked()
{
    emit consultarTodos();
}

void ViewConsultarPessoa::mostrar(QList<ModelPessoa> *list){
    ViewTreeWidgetItem *item;

    ModelPessoa* m;
    ui->treeWidget->clear();

    for(int i = 0; i < list->count(); i++){
        m = list->at(i);
        item = new ViewTreeWidgetItem (list->at(i));

        item->setText(0,QString::number(m->getIdPessoa()));
        item->setText(1,nome);
        item->setText(2,m->getDtNascimento().toString("dd/mm/yyyy"));
        item->setText(3, m->getSexo());

        ui->treeWidget->addTopLevelItem(item);
    }
    delete list;
}
