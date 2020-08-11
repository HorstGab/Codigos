/********************************************************************************
** Form generated from reading UI file 'viewconsultarpessoa.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWCONSULTARPESSOA_H
#define UI_VIEWCONSULTARPESSOA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewConsultarPessoa
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbNovo;
    QPushButton *pbImprimir;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbFechar;

    void setupUi(QWidget *ViewConsultarPessoa)
    {
        if (ViewConsultarPessoa->objectName().isEmpty())
            ViewConsultarPessoa->setObjectName(QStringLiteral("ViewConsultarPessoa"));
        ViewConsultarPessoa->resize(541, 323);
        verticalLayout_2 = new QVBoxLayout(ViewConsultarPessoa);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(ViewConsultarPessoa);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(ViewConsultarPessoa);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(ViewConsultarPessoa);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(ViewConsultarPessoa);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(ViewConsultarPessoa);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(ViewConsultarPessoa);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_4 = new QLabel(ViewConsultarPessoa);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox = new QComboBox(ViewConsultarPessoa);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, comboBox);


        horizontalLayout->addLayout(formLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(ViewConsultarPessoa);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(ViewConsultarPessoa);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(ViewConsultarPessoa);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        treeWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        treeWidget->header()->setDefaultSectionSize(50);
        treeWidget->header()->setMinimumSectionSize(30);

        verticalLayout_2->addWidget(treeWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pbNovo = new QPushButton(ViewConsultarPessoa);
        pbNovo->setObjectName(QStringLiteral("pbNovo"));

        horizontalLayout_2->addWidget(pbNovo);

        pbImprimir = new QPushButton(ViewConsultarPessoa);
        pbImprimir->setObjectName(QStringLiteral("pbImprimir"));

        horizontalLayout_2->addWidget(pbImprimir);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pbFechar = new QPushButton(ViewConsultarPessoa);
        pbFechar->setObjectName(QStringLiteral("pbFechar"));

        horizontalLayout_2->addWidget(pbFechar);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(ViewConsultarPessoa);

        QMetaObject::connectSlotsByName(ViewConsultarPessoa);
    } // setupUi

    void retranslateUi(QWidget *ViewConsultarPessoa)
    {
        ViewConsultarPessoa->setWindowTitle(QApplication::translate("ViewConsultarPessoa", "Consultar Pessoas...", 0));
        label->setText(QApplication::translate("ViewConsultarPessoa", "CPF:", 0));
        label_2->setText(QApplication::translate("ViewConsultarPessoa", "Nome:", 0));
        label_3->setText(QApplication::translate("ViewConsultarPessoa", "Data de Nascimento:", 0));
        label_4->setText(QApplication::translate("ViewConsultarPessoa", "Sexo:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("ViewConsultarPessoa", "Feminino", 0)
         << QApplication::translate("ViewConsultarPessoa", "Masculino", 0)
        );
        pushButton->setText(QApplication::translate("ViewConsultarPessoa", "Consultar", 0));
        pushButton_2->setText(QApplication::translate("ViewConsultarPessoa", "Limpar", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("ViewConsultarPessoa", "Editar", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("ViewConsultarPessoa", "Sexo", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("ViewConsultarPessoa", "Data Nascimento", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("ViewConsultarPessoa", "Nome", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("ViewConsultarPessoa", "CPF", 0));
        pbNovo->setText(QApplication::translate("ViewConsultarPessoa", "Novo", 0));
        pbImprimir->setText(QApplication::translate("ViewConsultarPessoa", "Imprimir", 0));
        pbFechar->setText(QApplication::translate("ViewConsultarPessoa", "Fechar", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewConsultarPessoa: public Ui_ViewConsultarPessoa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWCONSULTARPESSOA_H
