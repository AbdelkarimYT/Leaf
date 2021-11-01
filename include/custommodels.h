#ifndef CUSTOM_MODELS_H
#define CUSTOM_MODELS_H

#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelation>

namespace Models
{

}


class UserModel : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "users";

    enum Columns { id, name, username, password, created_at, updated_at };

public:
    explicit UserModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~UserModel();

};


class CustomerModel : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "customers";

    enum Columns { id, name, created_at, updated_at };

public:
    explicit CustomerModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~CustomerModel();

};


class CustomerPaymentstModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "customer_payments";

    enum Columns { id, user_id, customer_id, customer_bill_id, paid_amount, change_amount, date };

public:
    explicit CustomerPaymentstModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~CustomerPaymentstModel();

};


class SupplierModel : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "suppliers";

    enum Columns { id, name, email, phone, address, created_at, updated_at };

public:
    explicit SupplierModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~SupplierModel();

};

class ProductModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "products";

    enum Columns { id, category_id, name, price, description, created_at, updated_at };

public:
    explicit ProductModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~ProductModel();

};

class FamilyModel : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "familys";

    enum Columns { id, name };

public:
    explicit FamilyModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~FamilyModel();

};


class CategoryModel : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "categorys";

    enum Columns { id, family_id, name };

public:
    explicit CategoryModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~CategoryModel();

};


class InventoryModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "inventory";

    enum Columns { id, product_id, barcode, quantity, cost_price, expiration_date };

public:
    explicit InventoryModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~InventoryModel();

};

class CashModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "cash";

    enum Columns { id, user_id, operation_type, amount, date, description };

private:
    QSqlRelation hasOneUser;

public:
    explicit CashModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~CashModel();

};

#endif // CUSTOM_MODELS_H
