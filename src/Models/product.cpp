#include "product.h"

Product::Product(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db)
{
    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::category_id, Qt::Horizontal, tr("Category"));
    this->setHeaderData(Columns::name, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::price, Qt::Horizontal, tr("Price"));
    this->setHeaderData(Columns::stock, Qt::Horizontal, tr("Stock"));
    this->setHeaderData(Columns::description, Qt::Horizontal, tr("Description"));

    this->setRelation(Columns::category_id, QSqlRelation(Category::Table, "id", "name"));
}

Product::~Product()
{
}
