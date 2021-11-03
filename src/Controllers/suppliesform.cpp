#include "suppliesform.h"
#include "ui_suppliesform.h"

extern Supplier *suppliers;

SuppliesForm::SuppliesForm(QWidget *parent) : QWidget(parent), ui(new Ui::SuppliesForm)
{
    ui->setupUi(this);
    ui->suppliersTableView->setModel(suppliers);
}

SuppliesForm::~SuppliesForm()
{
    delete ui;
}
