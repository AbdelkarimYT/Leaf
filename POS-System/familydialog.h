#ifndef FAMILYDIALOG_H
#define FAMILYDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui { class FamilyDialog; }

class FamilyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FamilyDialog(QWidget *parent = nullptr);
    ~FamilyDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::FamilyDialog *ui;
};

#endif // FAMILYDIALOG_H
