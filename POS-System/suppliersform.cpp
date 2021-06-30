#include "suppliersform.h"
#include "ui_suppliersform.h"
#include "models.h"

SuppliersForm::SuppliersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuppliersForm)
{
    ui->setupUi(this);
    if (db.open())
    {
        ui->suppliersTable->setModel(suppliers);
        suppliers->select();
        db.close();
    }
}

SuppliersForm::~SuppliersForm()
{
    delete ui;
}
