#include "family.h"

Family::Family(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
}

Family::~Family()
{
}
