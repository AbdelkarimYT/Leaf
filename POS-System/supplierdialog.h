#ifndef SUPPLIERDIALOG_H
#define SUPPLIERDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui { class SupplierDialog; }

class SupplierDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SupplierDialog(QWidget *parent = nullptr);
    ~SupplierDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SupplierDialog *ui;
    QStandardItemModel *itemsModel;
};

#endif // SUPPLIERDIALOG_H
