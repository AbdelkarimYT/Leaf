#ifndef CUSTOMERS_FORM_H
#define CUSTOMERS_FORM_H

#include <QWidget>
#include <Customer>

namespace Ui { class CustomersForm; }

class CustomersForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomersForm(QWidget *parent = nullptr);
    ~CustomersForm();

private:
    Ui::CustomersForm *ui;
};

#endif // CUSTOMERS_FORM_H
