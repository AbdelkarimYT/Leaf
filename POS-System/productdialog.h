#ifndef productDIALOG_H
#define productDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui { class productDialog; }

class productDialog : public QDialog
{
    Q_OBJECT

public:
    explicit productDialog(QWidget *parent = nullptr);
    ~productDialog();

private slots:
    void on_addFamilyButton_clicked();
    void on_addCategoryButton_clicked();
    void on_dialogButtons_accepted();

private:
    Ui::productDialog *ui;
};

#endif // productDIALOG_H
