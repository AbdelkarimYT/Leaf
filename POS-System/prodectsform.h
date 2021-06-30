#ifndef PRODECTSFORM_H
#define PRODECTSFORM_H01110

#include <QWidget>
#include <QMessageBox>

namespace Ui { class ProdectsForm; }

class ProdectsForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProdectsForm(QWidget *parent = nullptr);
    ~ProdectsForm();

private:
    Ui::ProdectsForm *ui;
};

#endif // PRODECTSFORM_H
