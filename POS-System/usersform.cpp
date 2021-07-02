#include "usersform.h"
#include "ui_usersform.h"
#include "models.h"

UsersForm::UsersForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsersForm)
{
    ui->setupUi(this);
    ui->usersTable->setModel(users);
}

UsersForm::~UsersForm()
{
    delete ui;
}
