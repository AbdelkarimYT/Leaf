#include "inventory.h"

Inventory::Inventory(QObject *parent, QSqlDatabase db) : QSqlRelationalTableModel(parent, db)
{

    this->setTable(Table);

    this->setHeaderData(Columns::id, Qt::Horizontal, "#");
    this->setHeaderData(Columns::product_id, Qt::Horizontal, tr("Family"));
    this->setHeaderData(Columns::barcode, Qt::Horizontal, tr("Name"));
    this->setHeaderData(Columns::quantity, Qt::Horizontal, tr("Quantity"));
    this->setHeaderData(Columns::cost_price, Qt::Horizontal, tr("Cost Price"));
    this->setHeaderData(Columns::expiration_date, Qt::Horizontal, tr("Expiration Date"));
}

Inventory::~Inventory()
{
}