#ifndef SUPPLIER_PAYMENT_MODEL_H
#define SUPPLIER_PAYMENT_MODEL_H

#include <QSqlRelationalTableModel>
#include <User>
#include <Supplier>

namespace Model { class SupplierPayment; }

class SupplierPayment : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "supplier_payments";

    enum Columns { id, user_id, supplier_id, supplier_bill_id, paid_amount, change_amount, date };

public:
    explicit SupplierPayment(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~SupplierPayment();
};

#endif // SUPPLIER_PAYMENT_MODEL_H
