#include "customerpaymentsform.h"
#include "ui_customerpaymentsform.h"

extern CustomerPaymentstModel *customerPayments;

CustomerPaymentsForm::CustomerPaymentsForm(QWidget *parent) : QWidget(parent),  ui(new Ui::CustomerPaymentsForm)
{
    ui->setupUi(this);
    ui->customerPaymentsTableView->setModel(customerPayments);
}

CustomerPaymentsForm::~CustomerPaymentsForm()
{
    delete ui;
}
