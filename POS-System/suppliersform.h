#ifndef SUPPLIERSFORM_H
#define SUPPLIERSFORM_H

#include <QWidget>

namespace Ui {
class SuppliersForm;
}

class SuppliersForm : public QWidget
{
    Q_OBJECT

public:
    explicit SuppliersForm(QWidget *parent = nullptr);
    ~SuppliersForm();

private:
    Ui::SuppliersForm *ui;
};

#endif // SUPPLIERSFORM_H
