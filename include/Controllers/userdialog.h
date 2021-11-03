#ifndef USER_DIALOG_H
#define USER_DIALOG_H

#include <QDialog>
#include <QModelIndex>

namespace Ui { class UserDialog; }

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = nullptr, QModelIndex *model = nullptr, int arole = Qt::DisplayRole);
    ~UserDialog();

private:
    Ui::UserDialog *ui;
};

#endif // USER_DIALOG_H
