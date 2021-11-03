#ifndef SUPPLIERPAYMENTSFORM_H
#define SUPPLIERPAYMENTSFORM_H

#include "customdelegates.h"

#include <QWidget>
#include <SupplierPayment>

namespace Ui {
class SupplierPaymentsForm;
}

class SupplierPaymentsForm : public QWidget
{
    Q_OBJECT

public:
    explicit SupplierPaymentsForm(QWidget *parent = nullptr);
    ~SupplierPaymentsForm();

private:
    Ui::SupplierPaymentsForm *ui;
};

#endif // SUPPLIERPAYMENTSFORM_H
