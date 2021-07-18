#include "suppliersform.h"
#include "ui_suppliersform.h"
#include "models.h"

SuppliersForm::SuppliersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuppliersForm)
{
    ui->setupUi(this);
    ui->suppliersTable->setModel(suppliers);
}

SuppliersForm::~SuppliersForm()
{
    delete ui;
}
