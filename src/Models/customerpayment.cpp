#include "customerpayment.h"

CustomerPayment::CustomerPayment(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db)
{
    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::user_id, Qt::Horizontal, tr("User"));
    this->setHeaderData(Columns::customer_id, Qt::Horizontal, tr("Custome"));
    this->setHeaderData(Columns::customer_bill_id, Qt::Horizontal, tr("Bill Number"));
    this->setHeaderData(Columns::paid_amount, Qt::Horizontal, tr("Paid Amount"));
    this->setHeaderData(Columns::change_amount, Qt::Horizontal, tr("Change Amount"));
    this->setHeaderData(Columns::date, Qt::Horizontal, tr("Date"));

    this->setRelation(Columns::user_id, QSqlRelation(User::Table, "id", "name"));
    this->setRelation(Columns::customer_id, QSqlRelation(Customer::Table, "id", "name"));
    //this->setRelation(Columns::customer_bill_id, QSqlRelation(// TODO::Table, "id", "name"));
}

CustomerPayment::~CustomerPayment()
{
}
