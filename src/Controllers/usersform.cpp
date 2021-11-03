#include "usersform.h"
#include "ui_usersform.h"

extern User *users;

UsersForm::UsersForm(QWidget *parent) : QWidget(parent), ui(new Ui::UsersForm)
{
    ui->setupUi(this);
    ui->usersTableView->setModel(users);
    ui->usersTableView->setItemDelegateForColumn(User::Columns::created_at, new DateTimeDelegate);
    ui->usersTableView->setItemDelegateForColumn(User::Columns::updated_at, new DateTimeDelegate);

    //ui->usersTableView->horizontalHeader()->setSectionResizeMode(UserModel::Columns::id, QHeaderView::ResizeToContents);
    //ui->usersTableView->horizontalHeader()->setSectionResizeMode(UserModel::Columns::name, QHeaderView::Stretch);
    //ui->usersTableView->horizontalHeader()->setSectionResizeMode(UserModel::Columns::username, QHeaderView::ResizeToContents);
    //ui->usersTableView->horizontalHeader()->setSectionResizeMode(UserModel::Columns::password, QHeaderView::ResizeToContents);
    //ui->usersTableView->horizontalHeader()->setSectionResizeMode(UserModel::Columns::created_at, QHeaderView::ResizeToContents);
    //ui->usersTableView->horizontalHeader()->setSectionResizeMode(UserModel::Columns::updated_at, QHeaderView::ResizeToContents);
}

UsersForm::~UsersForm()
{
    delete ui;
}
