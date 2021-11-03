#ifndef CUSTOMER_PAYMENTS_FORM_H
#define CUSTOMER_PAYMENTS_FORM_H

#include <QWidget>
#include <CustomerPayment>

namespace Ui { class CustomerPaymentsForm; }

class CustomerPaymentsForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerPaymentsForm(QWidget *parent = nullptr);
    ~CustomerPaymentsForm();

private:
    Ui::CustomerPaymentsForm *ui;
};

#endif // CUSTOMER_PAYMENTS_FORM_H
