#include "ordersform.h"
#include "ui_ordersform.h"
#include "models.h"

OrdersForm::OrdersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrdersForm)
{
    ui->setupUi(this);
    ui->ordersTabel->setModel(orders);
}

OrdersForm::~OrdersForm()
{
    delete ui;
}
