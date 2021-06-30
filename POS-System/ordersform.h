#ifndef ORDERSFORM_H
#define ORDERSFORM_H

#include <QWidget>

namespace Ui {
class OrdersForm;
}

class OrdersForm : public QWidget
{
    Q_OBJECT

public:
    explicit OrdersForm(QWidget *parent = nullptr);
    ~OrdersForm();

private:
    Ui::OrdersForm *ui;
};

#endif // ORDERSFORM_H
