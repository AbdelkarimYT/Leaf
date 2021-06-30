#ifndef SELLINGFORM_H
#define SELLINGFORM_H

#include <QWidget>
#include <QStringList>
#include <QStandardItemModel>

namespace Ui { class SellingForm; }

class SellingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SellingForm(QWidget *parent = nullptr);
    ~SellingForm();

private:
    Ui::SellingForm *ui;
};

#endif // SELLINGFORM_H
