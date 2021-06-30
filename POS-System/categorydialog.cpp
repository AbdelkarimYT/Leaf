#include "categorydialog.h"
#include "ui_categorydialog.h"
#include "models.h"

CategoryDialog::CategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoryDialog)
{
    ui->setupUi(this);
}

CategoryDialog::~CategoryDialog()
{
    delete ui;
}

void CategoryDialog::on_buttonBox_accepted()
{
    if (db.open())
    {
        QSqlQuery q(db);
        q.prepare("CALL RegisterCategory(:name, :description);");
        q.bindValue(":name", ui->category->text());
        q.bindValue(":description", ui->description->toPlainText());
        if (!q.exec())
        {
            QMessageBox::critical(this, "ERORR", q.lastError().text());
        }
        else
        {
            this->accept();
            categorys->select();
            db.close();
            QMessageBox::information(this, "Success", "Category added successfully.");
        }
    }
}

