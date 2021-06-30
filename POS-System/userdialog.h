#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui { class UserDialog; }

class UserDialog : public QDialog {

    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = nullptr);
    ~UserDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::UserDialog *ui;
};

#endif // USERDIALOG_H
