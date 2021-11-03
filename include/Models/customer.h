#ifndef CUSTOMER_MODEL_H
#define CUSTOMER_MODEL_H

#include <QSqlTableModel>

namespace Model { class Customer; }

class Customer : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "customers";

    enum Columns { id, name, created_at, updated_at };

public:
    explicit Customer(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~Customer();
};

#endif // CUSTOMER_MODEL_H