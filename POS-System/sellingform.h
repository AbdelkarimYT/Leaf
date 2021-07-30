#ifndef SELLINGFORM_H
#define SELLINGFORM_H

#include <QWidget>
#include <QCompleter>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QSqlQueryModel>

namespace Ui { class SellingForm; }

class SellingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SellingForm(QWidget *parent = nullptr);
    ~SellingForm();

private slots:
    void on_addItemBtn_clicked();

    void on_filter_textChanged(const QString &arg1);

private:
    Ui::SellingForm       *ui;
    QStandardItemModel    *itemsModel;
    QSortFilterProxyModel *sortModel;
    QSqlQueryModel        *sqlitemsModel;
};

#endif // SELLINGFORM_H
