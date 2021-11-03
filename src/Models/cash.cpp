#include "cash.h"

Cash::Cash(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db)
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

Cash::~Cash()
{
}