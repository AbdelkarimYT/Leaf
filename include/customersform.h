#ifndef CUSTOMERSFORM_H
#define CUSTOMERSFORM_H

#include "custommodels.h"
#include "customdelegates.h"

#include <QWidget>

namespace Ui {
class CustomersForm;
}

class CustomersForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomersForm(QWidget *parent = nullptr);
    ~CustomersForm();

private:
    Ui::CustomersForm *ui;
};

#endif // CUSTOMERSFORM_H
