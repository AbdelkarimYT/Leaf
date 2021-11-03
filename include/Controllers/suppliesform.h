#ifndef SUPPLIES_FORM_H
#define SUPPLIES_FORM_H

#include <QWidget>
#include <Supplier>

namespace Ui { class SuppliesForm; }

class SuppliesForm : public QWidget
{
    Q_OBJECT

public:
    explicit SuppliesForm(QWidget *parent = nullptr);
    ~SuppliesForm();

private:
    Ui::SuppliesForm *ui;
};

#endif // SUPPLIES_FORM_H
