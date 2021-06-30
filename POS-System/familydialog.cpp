#include "familydialog.h"
#include "ui_familydialog.h"
#include "models.h"

FamilyDialog::FamilyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FamilyDialog)
{
    ui->setupUi(this);
}

FamilyDialog::~FamilyDialog()
{
    delete ui;
}

void FamilyDialog::on_buttonBox_accepted()
{
    if (db.open())
    {
        QSqlQuery query(db);
        query.prepare("CALL RegisterFamily(:name, :description);");
        query.bindValue(":name", ui->familyName->text());
        query.bindValue(":description", ui->description->toPlainText());
        if (!query.exec())
        {
            QMessageBox::critical(this, "ERORR", query.lastError().text());
        }
        else
        {
            this->accept();
            familys->select();
            db.close();
            QMessageBox::information(this, "Success", "Family added successfully.");
        }
    }
}

