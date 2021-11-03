#ifndef CASH_FORM_H
#define CASH_FORM_H

#include <QWidget>
#include <Cash>
#include <QSqlRelationalDelegate>
#include <MonyDelegate>
#include <DateTimeDelegate>
#include <TextDelegate>

namespace Ui { class CashForm; }

class CashForm : public QWidget
{
    Q_OBJECT

public:
    explicit CashForm(QWidget *parent = nullptr);
    ~CashForm();

private:
    Ui::CashForm *ui;
    QSqlRelationalDelegate *userIdDelegate;
    MonyDelegate *amountDelegate;
    DateTimeDelegate *dateDelegate;
    TextDelegate *descriptionDelegate;
};

#endif // CASH_FORM_H
