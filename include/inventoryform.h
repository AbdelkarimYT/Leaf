#ifndef INVENTORYFORM_H
#define INVENTORYFORM_H

#include "custommodels.h"
#include "customdelegates.h"

#include <QWidget>

namespace Ui {
class InventoryForm;
}

class InventoryForm : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryForm(QWidget *parent = nullptr);
    ~InventoryForm();

private:
    Ui::InventoryForm *ui;
};

#endif // INVENTORYFORM_H
