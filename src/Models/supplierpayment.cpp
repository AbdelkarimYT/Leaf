#include "supplierpayment.h"

SupplierPayment::SupplierPayment(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db)
{
    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::user_id, Qt::Horizontal, tr("User"));
    this->setHeaderData(Columns::supplier_id, Qt::Horizontal, tr("Supplier"));
    this->setHeaderData(Columns::supplier_bill_id, Qt::Horizontal, tr("Bill Number"));
    this->setHeaderData(Columns::paid_amount, Qt::Horizontal, tr("Paid Amount"));
    this->setHeaderData(Columns::change_amount, Qt::Horizontal, tr("Change Amount"));
    this->setHeaderData(Columns::date, Qt::Horizontal, tr("Date"));

    this->setRelation(Columns::user_id, QSqlRelation(User::Table, "id", "name"));
    this->setRelation(Columns::supplier_id, QSqlRelation(Supplier::Table, "id", "name"));
    //this->setRelation(Columns::supplier_bill_id, QSqlRelation(CategoryModel::Table, "id", "name"));
}

SupplierPayment::~SupplierPayment()
{
}
