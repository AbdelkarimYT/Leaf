#ifndef PRODUCT_MODEL_H
#define PRODUCT_MODEL_H

#include <QSqlRelationalTableModel>
#include <Category>

namespace Model { class Product; }

class Product : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "products";

    enum Columns { id, category_id, name, price, stock, description, };

public:
    explicit Product(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~Product();
};

#endif // PRODUCT_MODEL_H
