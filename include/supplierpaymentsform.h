#ifndef SUPPLIERPAYMENTSFORM_H
#define SUPPLIERPAYMENTSFORM_H

#include "custommodels.h"
#include "customdelegates.h"

#include <QWidget>

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
