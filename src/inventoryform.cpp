#include "inventoryform.h"
#include "ui_inventoryform.h"

extern InventoryModel *inventory;

InventoryForm::InventoryForm(QWidget *parent) : QWidget(parent), ui(new Ui::InventoryForm)
{
    ui->setupUi(this);
    ui->inventoryTableView->setModel(inventory);
}

InventoryForm::~InventoryForm()
{
    delete ui;
}
