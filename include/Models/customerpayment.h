#ifndef CUSTOMER_PAYMENT_MODEL_H
#define CUSTOMER_PAYMENT_MODEL_H

#include <QSqlRelationalTableModel>
#include <User>
#include <Customer>

namespace Model { class CustomerPayment; }

class CustomerPayment : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "customer_payments";

    enum Columns { id, user_id, customer_id, customer_bill_id, paid_amount, change_amount, date };

public:
    explicit CustomerPayment(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~CustomerPayment();
};

#endif // CUSTOMER_PAYMENT_MODEL_H
