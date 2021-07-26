#include "productdialog.h"
#include "ui_productdialog.h"
#include "models.h"
#include "familydialog.h"
#include "categorydialog.h"


productDialog::productDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::productDialog)
{
    ui->setupUi(this);
    ui->family->setModel(familys);
    ui->category->setModel(categorys);
    ui->family->setModelColumn(1);
    ui->category->setModelColumn(1);
    ui->category->setCurrentIndex(-1);
    ui->family->setCurrentIndex(-1);
}

productDialog::~productDialog()
{
    delete ui;
}

void productDialog::on_addFamilyButton_clicked()
{
    FamilyDialog d(this);
    if (d.exec())
    {
        ui->family->setCurrentIndex(familys->rowCount() - 1);
    }
}


void productDialog::on_addCategoryButton_clicked()
{
    CategoryDialog d(this);
    if (d.exec())
    {
        ui->category->setCurrentIndex(categorys->rowCount() - 1);
    }
}

void productDialog::on_dialogButtons_accepted()
{
    if (db.open())
    {
        QSqlQuery q(db);
        q.prepare("CALL RegisterProduct(:name, :family, :category, :price, :description);");
        q.bindValue(":name", ui->name->text());
        q.bindValue(":family", ui->family->currentText());
        q.bindValue(":category", ui->category->currentText());
        q.bindValue(":price", ui->price->value());
        q.bindValue(":description", ui->description->toPlainText());
        if (!q.exec())
            QMessageBox::critical(this, "ERORR", q.lastError().text());
        else
        {
            products->select();
            this->accept();
            QMessageBox::information(this, "Success", "product added successfully.");
        }
    }
}
