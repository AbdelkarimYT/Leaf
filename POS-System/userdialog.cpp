#include "userdialog.h"
#include "ui_userdialog.h"
#include "models.h"

UserDialog::UserDialog(QWidget *parent) : QDialog(parent), ui(new Ui::UserDialog) {
    ui->setupUi(this);
}

UserDialog::~UserDialog() {
    delete ui;
}

void UserDialog::on_buttonBox_accepted() {
    if (ui->password->text() != ui->confirmPassword->text())
    {
        QMessageBox::warning(this, "Password error", "Password does not match, try again.");
        return;
    }

    if (db.open())
    {
        QSqlQuery q(db);
        q.prepare("CALL RegisterUser(:name, :username, :password);");
        q.bindValue(":name", ui->name->text());
        q.bindValue(":username", ui->username->text());
        q.bindValue(":password", ui->password->text());
        if (!q.exec())
        {
            QMessageBox::critical(this, "ERORR", q.lastError().text());
        }
        else
        {
            db.close();
            accept();
            QMessageBox::information(this, "Success", "User added successfully.");
        }
    }
}

