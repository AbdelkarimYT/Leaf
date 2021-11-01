#include "custommodels.h"


CashModel::CashModel(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db)
{
    QSqlRelation hasOneUser("users", "id", "name");

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::user_id, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::operation_type, Qt::Horizontal, tr("Operation Type"));
    this->setHeaderData(Columns::amount, Qt::Horizontal, tr("Amount"));
    this->setHeaderData(Columns::date, Qt::Horizontal, tr("Date"));
    this->setHeaderData(Columns::description, Qt::Horizontal, tr("Description"));

    this->setRelation(Columns::user_id, hasOneUser);
}

CashModel::~CashModel()
{
}


UserModel::UserModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::username, Qt::Horizontal, tr("Username"));
    this->setHeaderData(Columns::password, Qt::Horizontal, tr("Password"));
    this->setHeaderData(Columns::created_at, Qt::Horizontal, tr("Created At"));
    this->setHeaderData(Columns::updated_at, Qt::Horizontal, tr("Updated At"));
}

UserModel::~UserModel()
{
}


CustomerModel::CustomerModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::created_at, Qt::Horizontal, tr("Created At"));
    this->setHeaderData(Columns::updated_at, Qt::Horizontal, tr("Updated At"));
}

CustomerModel::~CustomerModel()
{
}

CustomerPaymentstModel::CustomerPaymentstModel(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db)
{
    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::user_id, Qt::Horizontal, tr("User"));
    this->setHeaderData(Columns::customer_id, Qt::Horizontal, tr("Custome"));
    this->setHeaderData(Columns::customer_bill_id, Qt::Horizontal, tr("Bill Number"));
    this->setHeaderData(Columns::paid_amount, Qt::Horizontal, tr("Paid Amount"));
    this->setHeaderData(Columns::change_amount, Qt::Horizontal, tr("Change Amount"));
    this->setHeaderData(Columns::date, Qt::Horizontal, tr("Date"));

    this->setRelation(Columns::user_id, QSqlRelation(UserModel::Table, "id", "name"));
    this->setRelation(Columns::customer_id, QSqlRelation(CustomerModel::Table, "id", "name"));
    //this->setRelation(Columns::customer_bill_id, QSqlRelation(// TODO::Table, "id", "name"));
}

CustomerPaymentstModel::~CustomerPaymentstModel()
{
}

SupplierModel::SupplierModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{
    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::email, Qt::Horizontal, tr("Email"));
    this->setHeaderData(Columns::phone, Qt::Horizontal, tr("Phone"));
    this->setHeaderData(Columns::address, Qt::Horizontal, tr("Address"));
    this->setHeaderData(Columns::created_at, Qt::Horizontal, tr("Created At"));
    this->setHeaderData(Columns::updated_at, Qt::Horizontal, tr("Updated At"));
}

SupplierModel::~SupplierModel()
{
}

ProductModel::ProductModel(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db)
{
    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::category_id, Qt::Horizontal, tr("Category"));
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::price, Qt::Horizontal, tr("Price At"));
    this->setHeaderData(Columns::description, Qt::Horizontal, tr("Description"));
    this->setHeaderData(Columns::created_at, Qt::Horizontal, tr("Created At"));
    this->setHeaderData(Columns::updated_at, Qt::Horizontal, tr("Updated At"));

    this->setRelation(Columns::category_id, QSqlRelation(CategoryModel::Table, "id", "name"));
}

ProductModel::~ProductModel()
{
}


FamilyModel::FamilyModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
}

FamilyModel::~FamilyModel()
{
}


InventoryModel::InventoryModel(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::product_id, Qt::Horizontal, tr("Family"));
    this->setHeaderData(Columns::barcode, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::quantity, Qt::Horizontal, tr("Quantity"));
    this->setHeaderData(Columns::cost_price, Qt::Horizontal, tr("Cost Price"));
    this->setHeaderData(Columns::expiration_date, Qt::Horizontal, tr("Expiration Date"));
}

InventoryModel::~InventoryModel()
{
}


CategoryModel::CategoryModel(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::family_id, Qt::Horizontal, tr("Family"));
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
}

CategoryModel::~CategoryModel()
{
}
