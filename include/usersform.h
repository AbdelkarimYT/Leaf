#ifndef USERSFORM_H
#define USERSFORM_H

#include "custommodels.h"
#include "customdelegates.h"

#include <QWidget>

namespace Ui {
class UsersForm;
}

class UsersForm : public QWidget
{
    Q_OBJECT

public:
    explicit UsersForm(QWidget *parent = nullptr);
    ~UsersForm();

private:
    Ui::UsersForm *ui;
};

#endif // USERSFORM_H
