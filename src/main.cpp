#include "mainwindow.h"
#include "custommodels.h"

#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>

QSqlDatabase db;
UserModel *users;
CustomerModel *customers;
CustomerPaymentstModel *customerPayments;
SupplierModel *suppliers;
ProductModel *products;
InventoryModel *inventory;
FamilyModel *familys;
CategoryModel *categors;
CashModel *cash;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    db = QSqlDatabase::addDatabase("QSQLITE", "LEAF-CONNECTION");
    db.setDatabaseName("leaf.db");

    if (!db.open())
    {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        a.quit();
        return 0;
    }

    users = new UserModel(nullptr, db);
    customers = new CustomerModel(nullptr, db);
    customerPayments = new CustomerPaymentstModel(nullptr, db);
    suppliers = new SupplierModel(nullptr, db);
    products = new ProductModel(nullptr, db);
    inventory = new InventoryModel(nullptr, db);
    familys= new FamilyModel(nullptr, db);
    categors = new CategoryModel(nullptr, db);
    cash = new CashModel(users, db);

    users->select();
    customers->select();
    customerPayments->select();
    suppliers->select();
    products->select();
    inventory->select();
    familys->select();
    categors->select();
    cash->select();

    MainWindow w;
    w.show();

    return a.exec();
}
