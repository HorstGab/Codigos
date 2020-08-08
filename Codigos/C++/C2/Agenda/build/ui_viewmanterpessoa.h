/********************************************************************************
** Form generated from reading UI file 'viewmanterpessoa.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWMANTERPESSOA_H
#define UI_VIEWMANTERPESSOA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewManterPessoa
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *nome;
    QLabel *label_4;
    QDateEdit *dtNascimento;
    QLabel *label_2;
    QLineEdit *idPessoa;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *SexoMasculino;
    QRadioButton *SexoFeminino;
    QLineEdit *cpf;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbSalvar;
    QPushButton *pbExcluir;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbCancelar;

    void setupUi(QWidget *ViewManterPessoa)
    {
        if (ViewManterPessoa->objectName().isEmpty())
            ViewManterPessoa->setObjectName(QStringLiteral("ViewManterPessoa"));
        ViewManterPessoa->resize(400, 186);
        verticalLayout = new QVBoxLayout(ViewManterPessoa);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ViewManterPessoa);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_3 = new QLabel(ViewManterPessoa);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        nome = new QLineEdit(ViewManterPessoa);
        nome->setObjectName(QStringLiteral("nome"));

        gridLayout->addWidget(nome, 2, 1, 1, 1);

        label_4 = new QLabel(ViewManterPessoa);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        dtNascimento = new QDateEdit(ViewManterPessoa);
        dtNascimento->setObjectName(QStringLiteral("dtNascimento"));

        gridLayout->addWidget(dtNascimento, 3, 1, 1, 1);

        label_2 = new QLabel(ViewManterPessoa);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        idPessoa = new QLineEdit(ViewManterPessoa);
        idPessoa->setObjectName(QStringLiteral("idPessoa"));
        idPessoa->setEnabled(false);
        idPessoa->setReadOnly(true);

        gridLayout->addWidget(idPessoa, 0, 1, 1, 1);

        label_5 = new QLabel(ViewManterPessoa);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        SexoMasculino = new QRadioButton(ViewManterPessoa);
        SexoMasculino->setObjectName(QStringLiteral("SexoMasculino"));

        horizontalLayout_2->addWidget(SexoMasculino);

        SexoFeminino = new QRadioButton(ViewManterPessoa);
        SexoFeminino->setObjectName(QStringLiteral("SexoFeminino"));

        horizontalLayout_2->addWidget(SexoFeminino);


        gridLayout->addLayout(horizontalLayout_2, 4, 1, 1, 1);

        cpf = new QLineEdit(ViewManterPessoa);
        cpf->setObjectName(QStringLiteral("cpf"));

        gridLayout->addWidget(cpf, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbSalvar = new QPushButton(ViewManterPessoa);
        pbSalvar->setObjectName(QStringLiteral("pbSalvar"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/botaoGravar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSalvar->setIcon(icon);

        horizontalLayout->addWidget(pbSalvar);

        pbExcluir = new QPushButton(ViewManterPessoa);
        pbExcluir->setObjectName(QStringLiteral("pbExcluir"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/REMOVER.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pbExcluir->setIcon(icon1);

        horizontalLayout->addWidget(pbExcluir);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbCancelar = new QPushButton(ViewManterPessoa);
        pbCancelar->setObjectName(QStringLiteral("pbCancelar"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/fechar.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pbCancelar->setIcon(icon2);

        horizontalLayout->addWidget(pbCancelar);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(idPessoa, cpf);
        QWidget::setTabOrder(cpf, nome);
        QWidget::setTabOrder(nome, dtNascimento);
        QWidget::setTabOrder(dtNascimento, SexoMasculino);
        QWidget::setTabOrder(SexoMasculino, SexoFeminino);
        QWidget::setTabOrder(SexoFeminino, pbSalvar);
        QWidget::setTabOrder(pbSalvar, pbExcluir);
        QWidget::setTabOrder(pbExcluir, pbCancelar);

        retranslateUi(ViewManterPessoa);

        QMetaObject::connectSlotsByName(ViewManterPessoa);
    } // setupUi

    void retranslateUi(QWidget *ViewManterPessoa)
    {
        ViewManterPessoa->setWindowTitle(QApplication::translate("ViewManterPessoa", "Manter pessoa...", 0));
        label->setText(QApplication::translate("ViewManterPessoa", "Nome:", 0));
        label_3->setText(QApplication::translate("ViewManterPessoa", "Id:", 0));
        label_4->setText(QApplication::translate("ViewManterPessoa", "Data de Nascimento:", 0));
        label_2->setText(QApplication::translate("ViewManterPessoa", "CPF:", 0));
        label_5->setText(QApplication::translate("ViewManterPessoa", "Sexo:", 0));
        SexoMasculino->setText(QApplication::translate("ViewManterPessoa", "Masculino", 0));
        SexoFeminino->setText(QApplication::translate("ViewManterPessoa", "Feminino", 0));
        pbSalvar->setText(QApplication::translate("ViewManterPessoa", "Salvar", 0));
        pbExcluir->setText(QApplication::translate("ViewManterPessoa", "Excluir", 0));
        pbCancelar->setText(QApplication::translate("ViewManterPessoa", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewManterPessoa: public Ui_ViewManterPessoa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWMANTERPESSOA_H
