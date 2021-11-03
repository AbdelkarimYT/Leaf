#include "user.h"

User::User(QObject *parent, QSqlDatabase db) : QSqlTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::username, Qt::Horizontal, tr("Username"));
    this->setHeaderData(Columns::password, Qt::Horizontal, tr("Password"));
    this->setHeaderData(Columns::created_at, Qt::Horizontal, tr("Created At"));
    this->setHeaderData(Columns::updated_at, Qt::Horizontal, tr("Updated At"));
}

User::~User()
{
}
