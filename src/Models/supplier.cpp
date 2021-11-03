#include "supplier.h"

Supplier::Supplier(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
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

Supplier::~Supplier()
{
}