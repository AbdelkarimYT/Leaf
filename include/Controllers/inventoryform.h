#ifndef INVENTORY_FORM_H
#define INVENTORY_FORM_H

#include <QWidget>
#include <Inventory>

namespace Ui { class InventoryForm; }

class InventoryForm : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryForm(QWidget *parent = nullptr);
    ~InventoryForm();

private:
    Ui::InventoryForm *ui;
};

#endif // INVENTORY_FORM_H
