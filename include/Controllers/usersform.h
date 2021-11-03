#ifndef USERS_FORM_H
#define USERS_FORM_H

#include <QWidget>
#include <User>
#include <DateTimeDelegate>

namespace Ui { class UsersForm; }

class UsersForm : public QWidget
{
    Q_OBJECT

public:
    explicit UsersForm(QWidget *parent = nullptr);
    ~UsersForm();

private:
    Ui::UsersForm *ui;
};

#endif // USERS_FORM_H
