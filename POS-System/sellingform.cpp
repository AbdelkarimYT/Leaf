#include "sellingform.h"
#include "ui_sellingform.h"
#include "models.h"

SellingForm::SellingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellingForm)
{
    ui->setupUi(this);

    itemsModel    = new QSqlRelationalTableModel(ui->itemsTabel, db);
    itemsDelegate = new QSqlRelationalDelegate();
    sortModel     = new QSortFilterProxyModel();
    sqlitemsModel = new QSqlQueryModel();

    itemsModel->setTable("consumed_items");
    itemsModel->setRelation(1, QSqlRelation("products", "id", "name"));
    itemsModel->setHeaderData(0, Qt::Horizontal, "#");
    itemsModel->setHeaderData(1, Qt::Horizontal, "Product Name");
    itemsModel->setHeaderData(2, Qt::Horizontal, "Quantity");
    itemsModel->setHeaderData(3, Qt::Horizontal, "Unit Price");
    itemsModel->setHeaderData(4, Qt::Horizontal, "Total");
    itemsModel->setEditStrategy(QSqlTableModel::OnRowChange);
    itemsModel->select();

    sqlitemsModel->setQuery(" \
        SELECT products.id, name, price, sum(quantity) as quantity, min(expiration_date) as min_expiration_date, max(expiration_date) as max_expiration_date \
        FROM products, inventory \
        WHERE products.id = inventory.product_id \
        AND NOW() < expiration_date \
        GROUP BY product_id");
    sqlitemsModel->query().exec();

    sortModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    sortModel->setFilterKeyColumn(-1);
    sortModel->setSourceModel(itemsModel);
    sortModel->setDynamicSortFilter(true);

    ui->product->setModel(sqlitemsModel);
    ui->product->setModelColumn(1);

    ui->itemsTabel->setModel(itemsModel);
    ui->itemsTabel->hideColumn(0);
    ui->itemsTabel->setItemDelegate(itemsDelegate);

    ui->clientName->setModel(customers);
    ui->clientName->setModelColumn(1);

    QSqlQuery getTotalQuery("SELECT sum(total) FROM consumed_items", db);
    getTotalQuery.next();
    ui->total->setValue(getTotalQuery.value(0).toDouble());
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
    int product_id = sqlitemsModel->index(index, 0).data().toInt();
    double price = sqlitemsModel->index(index, 2).data().toDouble();
    int qty = ui->quantity->value();
    double total = price * qty;

    QSqlQuery insertItemsQuery(db);
    insertItemsQuery.prepare(" \
        INSERT INTO consumed_items(product_id, consumed_quantity, unit_price, total) \
        VALUES (:product_id, :consumed_quantity, :unit_price, :total) \
        ON DUPLICATE KEY \
        UPDATE consumed_quantity=consumed_quantity + :consumed_quantity, total = (consumed_quantity) * unit_price;");
    insertItemsQuery.bindValue(":product_id", product_id);
    insertItemsQuery.bindValue(":consumed_quantity", qty);
    insertItemsQuery.bindValue(":unit_price", price);
    insertItemsQuery.bindValue(":total", total);
    insertItemsQuery.exec();
    itemsModel->select();

    QSqlQuery getTotalQuery("SELECT sum(total) FROM consumed_items", db);
    getTotalQuery.next();
    ui->total->setValue(getTotalQuery.value(0).toDouble());
}

void SellingForm::on_cancelRequestBtn_clicked()
{
    QSqlQuery deleteRequestsQuery("TRUNCATE consumed_items", db);
    ui->total->setValue(0);
    itemsModel->select();
}

void SellingForm::on_filter_textChanged(const QString &filterString)
{
    sortModel->setFilterFixedString(filterString);
}


