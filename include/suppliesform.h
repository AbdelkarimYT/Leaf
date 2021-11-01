#ifndef SUPPLIESFORM_H
#define SUPPLIESFORM_H

#include "custommodels.h"
#include "customdelegates.h"

#include <QWidget>

namespace Ui {
class SuppliesForm;
}

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
