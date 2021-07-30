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
    sqlitemsModel = new QSqlQueryModel();

    sqlitemsModel->setQuery("SELECT products.id, name, price, sum(quantity) as quantity, min(expiration_date) as min_expiration_date,  max(expiration_date) as max_expiration_date \
        FROM products, inventory \
        WHERE products.id = inventory.product_id \
        AND NOW() < expiration_date \
        GROUP BY product_id");
    sqlitemsModel->query().exec();

    sortModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    sortModel->setFilterKeyColumn(-1);
    sortModel->setSourceModel(itemsModel);

    itemsModel->setColumnCount(4);
    itemsModel->setHorizontalHeaderLabels(QStringList() << "Product Name" << "Quantity" << "Unit Price" << "Total");
    ui->itemsTabel->setModel(sortModel);

    ui->clientName->setModel(customers);
    ui->clientName->setModelColumn(1);

    ui->product->setModel(sqlitemsModel);
    ui->product->setModelColumn(1);
}

SellingForm::~SellingForm()
{
    delete ui;
    delete itemsModel;
    delete sortModel;
    delete sqlitemsModel;
}

void SellingForm::on_addItemBtn_clicked()
{
    int index = ui->product->currentIndex();
    //int id = sqlitemsModel->index(index, 0).data().toInt();
    QString name = sqlitemsModel->index(index, 1).data().toString();
    double price = sqlitemsModel->index(index, 2).data().toDouble();
    int qty = ui->quantity->value();
    double total = price * qty;
    //QString exd = sqlitemsModel->index(index, 2).data().toDouble();

    QList<QStandardItem*> item;
    item.append(new QStandardItem(name));
    item.append(new QStandardItem(QString::number(qty)));
    item.append(new QStandardItem(QString::number(price)));
    item.append(new QStandardItem(QString::number(total)));
    itemsModel->appendRow(item);
    ui->total->setValue(ui->total->value() + total);
}

void SellingForm::on_filter_textChanged(const QString &arg1)
{
    sortModel->setFilterFixedString(arg1);
}

