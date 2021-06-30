#include "sellingform.h"
#include "ui_sellingform.h"
#include "models.h"

SellingForm::SellingForm(QWidget *parent):
    QWidget(parent),
    ui(new Ui::SellingForm)
{
    ui->setupUi(this);
    ui->clientName->setModel(customers);
    ui->clientName->setModelColumn(1);
}

SellingForm::~SellingForm()
{
    delete ui;
}
