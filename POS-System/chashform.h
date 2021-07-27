#ifndef CHASHFORM_H
#define CHASHFORM_H

#include <QWidget>
#include <QSqlRelationalDelegate>

namespace Ui { class ChashForm; }

class ChashForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChashForm(QWidget *parent = nullptr);
    ~ChashForm();

private:
    Ui::ChashForm *ui;
    QSqlRelationalDelegate *cashInRelationalDelegate;
    QSqlRelationalDelegate *cashOutRelationalDelegate;
};

#endif // CHASHFORM_H
