#ifndef SUPPLIER_MODELS_H
#define SUPPLIER_MODELS_H

#include <QSqlTableModel>

namespace Model { class Supplier; }

class Supplier : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "suppliers";

    enum Columns { id, name, email, phone, address, created_at, updated_at };

public:
    explicit Supplier(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~Supplier();
};

#endif // SUPPLIER_MODELS_H
