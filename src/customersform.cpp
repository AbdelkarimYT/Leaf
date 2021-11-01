#include "customersform.h"
#include "ui_customersform.h"

extern CustomerModel *customers;

CustomersForm::CustomersForm(QWidget *parent) : QWidget(parent), ui(new Ui::CustomersForm)
{
    ui->setupUi(this);
    ui->customersTableView->setModel(customers);
}

CustomersForm::~CustomersForm()
{
    delete ui;
}
