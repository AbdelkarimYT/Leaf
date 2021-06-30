#include "clientsform.h"
#include "ui_clientsform.h"
#include "models.h"

ClientsForm::ClientsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientsForm)
{
    ui->setupUi(this);
    ui->customersTabel->setModel(customers);
}

ClientsForm::~ClientsForm()
{
    delete ui;
}
