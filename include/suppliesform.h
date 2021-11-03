#ifndef SUPPLIESFORM_H
#define SUPPLIESFORM_H

#include "customdelegates.h"

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

#endif // SUPPLIESFORM_H
