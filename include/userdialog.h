#ifndef USERDIALOG_H
#define USERDIALOG_H

#include "custommodels.h"
#include "customdelegates.h"

#include <QDialog>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = nullptr, QModelIndex &model = nullptr, int arole = Qt::DisplayRole);
    ~UserDialog();

private:
    Ui::UserDialog *ui;
};

#endif // USERDIALOG_H
