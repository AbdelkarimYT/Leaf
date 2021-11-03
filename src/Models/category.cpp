#include "category.h"

Category::Category(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::family_id, Qt::Horizontal, tr("Family"));
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
}

Category::~Category()
{
}