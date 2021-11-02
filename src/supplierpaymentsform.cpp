#include "supplierpaymentsform.h"
#include "ui_supplierpaymentsform.h"

extern SupplierPaymentModel *supplierPayments;

SupplierPaymentsForm::SupplierPaymentsForm(QWidget *parent) : QWidget(parent), ui(new Ui::SupplierPaymentsForm)
{
    ui->setupUi(this);
    ui->supplierPaymentsTableView->setModel(supplierPayments);
}

SupplierPaymentsForm::~SupplierPaymentsForm()
{
    delete ui;
}
