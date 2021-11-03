#ifndef SUPPLIER_PAYMENTS_FORM_H
#define SUPPLIER_PAYMENTS_FORM_H

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

#endif // SUPPLIER_PAYMENTS_FORM_H
