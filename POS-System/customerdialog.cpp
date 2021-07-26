#include "customerdialog.h"
#include "ui_customerdialog.h"
#include "models.h"

CustomerDialog::CustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
}

CustomerDialog::~CustomerDialog()
{
    delete ui;
}

void CustomerDialog::on_buttonBox_accepted()
{
    if (db.open())
    {
        QSqlQuery q(db);
        q.prepare("CALL RegisterCustomer(:name);");
        q.bindValue(":name", ui->name->text());
        if (!q.exec())
        {
            QMessageBox::critical(this, "ERORR", q.lastError().text());
            db.close();
        }
        else
        {
            accept();
            customers->select();
            QMessageBox::information(this, "Success", "Clinte added successfully.");
        }
    }
    else
    {
        QMessageBox::critical(this, "ERORR", db.lastError().text());
    }
}

