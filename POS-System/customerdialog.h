#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui { class CustomerDialog; }

class CustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDialog(QWidget *parent = nullptr);
    ~CustomerDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CustomerDialog *ui;
};

#endif // CUSTOMERDIALOG_H
