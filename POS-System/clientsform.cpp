#include "clientsform.h"
#include "ui_clientsform.h"
#include "models.h"

ClientsForm::ClientsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientsForm)
{
    ui->setupUi(this);

    customerPaymentsDelegate = new QSqlRelationalDelegate();

    ui->customersTabel->setModel(customers);
    ui->customerPaymentsTabel->setModel(customerPayments);
    ui->customerPaymentsTabel->setItemDelegate(customerPaymentsDelegate);
}

ClientsForm::~ClientsForm()
{
    delete ui;
    delete customerPaymentsDelegate;
}
