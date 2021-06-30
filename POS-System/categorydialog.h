#ifndef CATEGORYDIALOG_H
#define CATEGORYDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui { class CategoryDialog; }

class CategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CategoryDialog(QWidget *parent = nullptr);
    ~CategoryDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CategoryDialog *ui;
};

#endif // CATEGORYDIALOG_H
