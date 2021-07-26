#ifndef INVENTORYFORM_H
#define INVENTORYFORM_H

#include <QWidget>
#include <QSqlRelationalDelegate>

namespace Ui {
class InventoryForm;
}

class InventoryForm : public QWidget
{
    Q_OBJECT

public:
    explicit InventoryForm(QWidget *parent = nullptr);
    ~InventoryForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InventoryForm *ui;
    QSqlRelationalDelegate *inventoryRelationalDelegate;
};

#endif // INVENTORYFORM_H
