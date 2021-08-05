#ifndef productsFORM_H
#define productsFORM_H01110

#include <QWidget>
#include <QSortFilterProxyModel>
#include <QSqlRelationalDelegate>

namespace Ui { class productsForm; }

class productsForm : public QWidget
{
    Q_OBJECT

public:
    explicit productsForm(QWidget *parent = nullptr);
    ~productsForm();

private slots:
    void on_familySearch_textChanged(const QString &filterString);

private:
    Ui::productsForm *ui;
    QSortFilterProxyModel *familyFilterModel;
    QSqlRelationalDelegate *productRelationalDelegate;
};

#endif // productsFORM_H
