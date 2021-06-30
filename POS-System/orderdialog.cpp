#include "orderdialog.h"
#include "ui_orderdialog.h"
#include "models.h"

OrderDialog::OrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderDialog)
{
    ui->setupUi(this);
    ui->supplier->setModel(suppliers);
    ui->supplier->setModelColumn(2);
    suppliers->select();
}

OrderDialog::~OrderDialog()
{
    delete ui;
}
