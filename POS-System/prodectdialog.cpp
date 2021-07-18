#include "prodectdialog.h"
#include "ui_prodectdialog.h"
#include "models.h"
#include "familydialog.h"
#include "categorydialog.h"


ProdectDialog::ProdectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProdectDialog)
{
    ui->setupUi(this);
    ui->family->setModel(familys);
    ui->category->setModel(categorys);
    ui->family->setModelColumn(2);
    ui->category->setModelColumn(2);
    ui->category->setCurrentIndex(-1);
    ui->family->setCurrentIndex(-1);
}

ProdectDialog::~ProdectDialog()
{
    delete ui;
}

void ProdectDialog::on_addFamilyButton_clicked()
{
    FamilyDialog d(this);
    if (d.exec())
    {
        ui->family->setCurrentIndex(familys->rowCount() - 1);
    }
}


void ProdectDialog::on_addCategoryButton_clicked()
{
    CategoryDialog d(this);
    if (d.exec())
    {
        ui->category->setCurrentIndex(categorys->rowCount() - 1);
    }
}

void ProdectDialog::on_discount_valueChanged(double value)
{
    ui->discount_100->setValue((value * 100) / ui->price->value());
}


void ProdectDialog::on_discount_100_valueChanged(int value)
{
    ui->discount->setValue((value * ui->price->value()) / 100 );
}


void ProdectDialog::on_dialogButtons_accepted()
{
    if (db.open())
    {
        QSqlQuery q(db);
        q.prepare("CALL RegisterProdect(:name, :family, :category, :price, :alert_quantit, :reorder_quantity, :description);");
        q.bindValue(":name", ui->name->text());
        q.bindValue(":family", ui->family->currentText());
        q.bindValue(":category", ui->category->currentText());
        q.bindValue(":price", ui->price->value());
        q.bindValue(":alert_quantit", ui->alertQuantity->value());
        q.bindValue(":reorder_quantity", ui->reorderQuantity->value());
        q.bindValue(":description", ui->description->toPlainText());
        if (!q.exec())
        {
            QMessageBox::critical(this, "ERORR", q.lastError().text());
            db.close();
        }
        else
        {
            QString name = ui->name->text();
            QSqlQuery q(db);
            for (int index = 0; index < ui->barcodesList->count(); index++)
            {
                q.prepare("CALL RegisterBarcodes(:name, :value);");
                q.bindValue(":name", name);
                q.bindValue(":value", ui->barcodesList->item(index)->text());
                if (!q.exec())
                    QMessageBox::critical(this, "ERORR", q.lastError().text());
                q.clear();
            }
            accept();
            prodects->select();
            db.close();
            QMessageBox::information(this, "Success", "Prodect added successfully.");
        }
    }
}


void ProdectDialog::on_generateBarcodeButton_clicked()
{
    int r = QRandomGenerator64::global()->bounded(100000, 1000000);
    ui->barcode->setText(QString::number(r));
}


void ProdectDialog::on_addToListButton_clicked()
{
    ui->barcodesList->addItem(ui->barcode->text());
    ui->barcode->clear();
}


void ProdectDialog::on_barcodesList_customContextMenuRequested(const QPoint &pos)
{
    if(!((ui->barcodesList->selectionModel()->selectedIndexes()).empty()))
    {
        QMenu m(ui->barcodesList);
        m.addAction(ui->actionUpdateBarcode);
        m.addAction(ui->actionDeleteBarcode);
        m.exec(QCursor::pos());
    }
}


void ProdectDialog::on_actionDeleteBarcode_triggered()
{
    qDeleteAll(ui->barcodesList->selectedItems());
}


void ProdectDialog::on_actionUpdateBarcode_triggered()
{
    int r = QRandomGenerator64::global()->bounded(100000, 1000000);
    ui->barcodesList->currentItem()->setText(QString::number(r));
}

