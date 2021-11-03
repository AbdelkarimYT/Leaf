#ifndef INVENTORY_MODEL_H
#define INVENTORY_MODEL_H

#include <QSqlRelationalTableModel>

namespace Model { class Inventory; }

class Inventory : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "inventory";

    enum Columns { id, product_id, barcode, quantity, cost_price, expiration_date };

public:
    explicit Inventory(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~Inventory();
};

#endif // INVENTORY_MODEL_H
