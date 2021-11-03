#ifndef CASHFORM_H
#define CASHFORM_H

#include "customdelegates.h"

#include <QWidget>
#include <Cash>

namespace Ui { class CashForm; }

class CashForm: public QWidget
{
    Q_OBJECT

public:
    explicit CashForm(QWidget *parent = nullptr);
    ~CashForm();

private:
    Ui::CashForm *ui;
    QSqlRelationalDelegate *userIdDelegate;
    QDoubleSpinBoxDelegate *amountDelegate;
    QDateTimeEditDelegate *dateDelegate;
    QPlainTextEditDelegate *descriptionDelegate;
};

#endif // CASHFORM_H
