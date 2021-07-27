#include "inventoryform.h"
#include "ui_inventoryform.h"
#include "models.h"

InventoryForm::InventoryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InventoryForm)
{
    ui->setupUi(this);

    inventoryRelationalDelegate = new QSqlRelationalDelegate();

    ui->inventoryTable->setModel(inventory);
    ui->inventoryTable->setItemDelegate(inventoryRelationalDelegate);
}

InventoryForm::~InventoryForm()
{
    delete ui;
    delete inventoryRelationalDelegate;
}

