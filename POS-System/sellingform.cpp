#include "sellingform.h"
#include "ui_sellingform.h"
#include "models.h"

SellingForm::SellingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellingForm)
{
    ui->setupUi(this);

    itemsModel = new QStandardItemModel();
    sortModel  = new QSortFilterProxyModel();

    sortModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    sortModel->setFilterKeyColumn(-1);
    sortModel->setSourceModel(itemsModel);

    itemsModel->setColumnCount(4);
    itemsModel->setHorizontalHeaderLabels(QStringList() << "Product Name" << "Quantity" << "Unit Price" << "Total");
    ui->itemsTabel->setModel(sortModel);

    ui->clientName->setModel(customers);
    ui->clientName->setModelColumn(1);

    ui->product->setModel(inventory);
    ui->product->setModelColumn(1);
}

SellingForm::~SellingForm()
{
    delete ui;
    delete itemsModel;
    delete sortModel;
}

void SellingForm::on_addItemBtn_clicked()
{
    //ui->product->currentData().;
    QList<QStandardItem*> item;
    QString name = ui->product->currentText();
    QString qty = QString::number(ui->quantity->value());
    QString uprice = "";
    QString total = "";
    item.append(new QStandardItem(name));
    item.append(new QStandardItem(qty));
    item.append(new QStandardItem("3"));
    item.append(new QStandardItem("4"));
    itemsModel->appendRow(item);
}

void SellingForm::on_filter_textChanged(const QString &arg1)
{
    sortModel->setFilterFixedString(arg1);
}

