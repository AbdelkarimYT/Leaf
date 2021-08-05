#ifndef SELLINGFORM_H
#define SELLINGFORM_H

#include <QWidget>
#include <QCompleter>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelation>
#include <QItemDelegate>
#include <QDoubleSpinBox>

namespace Ui { class SellingForm; }

class SellingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SellingForm(QWidget *parent = nullptr);
    ~SellingForm();

private slots:
    void on_addItemBtn_clicked();
    void on_filter_textChanged(const QString &filterString);

    void on_cancelRequestBtn_clicked();

private:
    Ui::SellingForm          *ui;
    QSqlRelationalTableModel *itemsModel;
    QSortFilterProxyModel    *sortModel;
    QSqlQueryModel           *sqlitemsModel;
    QSqlRelationalDelegate   *itemsDelegate;
};

#endif // SELLINGFORM_H
