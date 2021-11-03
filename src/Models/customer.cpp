#include "customer.h"

Customer::Customer(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::created_at, Qt::Horizontal, tr("Created At"));
    this->setHeaderData(Columns::updated_at, Qt::Horizontal, tr("Updated At"));
}

Customer::~Customer()
{
}