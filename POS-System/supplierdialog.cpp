#include "supplierdialog.h"
#include "ui_supplierdialog.h"

SupplierDialog::SupplierDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SupplierDialog) {
    ui->setupUi(this);
}

SupplierDialog::~SupplierDialog() {
    delete ui;
}

void SupplierDialog::on_buttonBox_accepted() {

}

