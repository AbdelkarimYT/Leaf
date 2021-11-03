#include <QApplication>
#include <MainWindow>

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>

#include <User>
#include <Customer>
#include <CustomerPayment>
#include <Supplier>
#include <SupplierPayment>
#include <Product>
#include <Inventory>
#include <Family>
#include <Category>
#include <Cash>

QSqlDatabase db;

User *users;
Customer *customers;
CustomerPayment *customerPayments;
Supplier *suppliers;
SupplierPayment *supplierPayments;
Product *products;
Inventory *inventory;
Family *familys;
Category *categors;
Cash *cash;

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

    users = new User(nullptr, db);
    customers = new Customer(nullptr, db);
    customerPayments = new CustomerPayment(nullptr, db);
    suppliers = new Supplier(nullptr, db);
    supplierPayments = new SupplierPayment(nullptr, db);
    products = new Product(nullptr, db);
    inventory = new Inventory(nullptr, db);
    familys= new Family(nullptr, db);
    categors = new Category(nullptr, db);
    cash = new Cash(users, db);

    users->select();
    customers->select();
    customerPayments->select();
    suppliers->select();
    supplierPayments->select();
    products->select();
    inventory->select();
    familys->select();
    categors->select();
    cash->select();

    MainWindow w;
    w.show();

    return a.exec();
}
