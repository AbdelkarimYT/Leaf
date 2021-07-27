#include "mainwindow.h"
#include "logindialog.h"
#include "models.h"

#include <QApplication>
#include <QSettings>
#include <QSplashScreen>
#include <QPixmap>
#include <QMessageBox>

QSqlDatabase   db;
QSqlRelationalTableModel *products;
QSqlTableModel *customers;
QSqlTableModel *suppliers;
QSqlRelationalTableModel *cashIn;
QSqlTableModel *cashOut;
QSqlTableModel *familys;
QSqlTableModel *categorys;
QSqlTableModel *orders;
QSqlTableModel *users;
QSqlRelationalTableModel *inventory;

int main(int argc, char *argv[])
{
    QApplication  a(argc, argv);
    QSplashScreen splash(QPixmap(":/Backgrounds/res/splash.jpg"));
    LoginDialog   d(nullptr);
    MainWindow    w;

    //a.setStyle("Fusion");
    splash.show();

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("abdelkarim");
    db.setPassword("toor");
    db.setDatabaseName("leaf_db");

    if (db.open())
    {
        if (!d.exec())
            return 0;

        products  = new QSqlRelationalTableModel(nullptr, db);
        users     = new QSqlTableModel(nullptr, db);
        customers = new QSqlTableModel(nullptr, db);
        suppliers = new QSqlTableModel(nullptr, db);
        cashIn    = new QSqlRelationalTableModel(nullptr, db);
        cashOut   = new QSqlTableModel(nullptr, db);
        familys   = new QSqlTableModel(nullptr, db);
        categorys = new QSqlTableModel(nullptr, db);
        orders    = new QSqlTableModel(nullptr, db);
        inventory = new QSqlRelationalTableModel(products, db);

        products->setTable("products");
        users->setTable("users");
        customers->setTable("customers");
        suppliers->setTable("suppliers");
        cashIn->setTable("cash_in");
        cashOut->setTable("cash_out");
        familys->setTable("familys");
        categorys->setTable("categorys");
        orders->setTable("orders");
        inventory->setTable("inventory");

        products->setHeaderData(0, Qt::Horizontal, "#");
        products->setHeaderData(1, Qt::Horizontal, "Family Name");
        products->setHeaderData(2, Qt::Horizontal, "Category Name");
        products->setHeaderData(3, Qt::Horizontal, "Product Name");
        products->setHeaderData(4, Qt::Horizontal, "Unit Price");
        products->setHeaderData(5, Qt::Horizontal, "Description");
        products->setHeaderData(6, Qt::Horizontal, "Created Date");
        products->setHeaderData(7, Qt::Horizontal, "Updated Date");
        users->setHeaderData(0, Qt::Horizontal, "#");
        users->setHeaderData(1, Qt::Horizontal, "Name");
        users->setHeaderData(2, Qt::Horizontal, "Username");
        users->setHeaderData(3, Qt::Horizontal, "Password");
        users->setHeaderData(4, Qt::Horizontal, "Created Date");
        users->setHeaderData(5, Qt::Horizontal, "Updated Date");
        customers->setHeaderData(0, Qt::Horizontal, "#");
        customers->setHeaderData(1, Qt::Horizontal, "Name");
        customers->setHeaderData(2, Qt::Horizontal, "Created Date");
        customers->setHeaderData(3, Qt::Horizontal, "Updated Date");
        familys->setHeaderData(0, Qt::Horizontal, "#");
        familys->setHeaderData(1, Qt::Horizontal, "Family Name");
        familys->setHeaderData(2, Qt::Horizontal, "Description");
        familys->setHeaderData(3, Qt::Horizontal, "Created Date");
        familys->setHeaderData(4, Qt::Horizontal, "Updated Date");
        categorys->setHeaderData(0, Qt::Horizontal, "#");
        categorys->setHeaderData(1, Qt::Horizontal, "Category Name");
        categorys->setHeaderData(2, Qt::Horizontal, "Description");
        categorys->setHeaderData(3, Qt::Horizontal, "Created Date");
        categorys->setHeaderData(4, Qt::Horizontal, "Updated Date");
        inventory->setHeaderData(0, Qt::Horizontal, "#");
        inventory->setHeaderData(1, Qt::Horizontal, "Product Name");
        inventory->setHeaderData(2, Qt::Horizontal, "Barcode");
        inventory->setHeaderData(3, Qt::Horizontal, "Quantity");
        inventory->setHeaderData(4, Qt::Horizontal, "Cost Price");
        inventory->setHeaderData(5, Qt::Horizontal, "Expiration Date");
        cashIn->setHeaderData(0, Qt::Horizontal, "#");
        cashIn->setHeaderData(1, Qt::Horizontal, "User Name");
        cashIn->setHeaderData(2, Qt::Horizontal, "Amount");
        cashIn->setHeaderData(3, Qt::Horizontal, "Transaction Date");
        cashIn->setHeaderData(4, Qt::Horizontal, "Description");
        cashOut->setHeaderData(0, Qt::Horizontal, "#");
        cashOut->setHeaderData(1, Qt::Horizontal, "User Name");
        cashOut->setHeaderData(2, Qt::Horizontal, "Amount");
        cashOut->setHeaderData(3, Qt::Horizontal, "Transaction Date");
        cashOut->setHeaderData(4, Qt::Horizontal, "Description");
        suppliers->setHeaderData(0, Qt::Horizontal, "#");
        suppliers->setHeaderData(1, Qt::Horizontal, "Supplier Name");
        suppliers->setHeaderData(2, Qt::Horizontal, "Email");
        suppliers->setHeaderData(3, Qt::Horizontal, "Phone Number");
        suppliers->setHeaderData(4, Qt::Horizontal, "Address");
        suppliers->setHeaderData(5, Qt::Horizontal, "Created Date");
        suppliers->setHeaderData(6, Qt::Horizontal, "Update Date");

        products->setRelation(1, QSqlRelation("familys", "id", "name"));
        products->setRelation(2, QSqlRelation("categorys", "id", "name"));
        inventory->setRelation(1, QSqlRelation("products", "id", "name"));
        cashIn->setRelation(1, QSqlRelation("users", "id", "name"));

        products->select();
        users->select();
        customers->select();
        suppliers->select();
        familys->select();
        categorys->select();
        cashIn->select();
        cashOut->select();
        orders->select();
        inventory->select();

        MainWindow w;
        w.showMaximized();
        //db.close();
        splash.finish(&w);

        return a.exec();
    }
    else
    {
        QMessageBox::critical(nullptr, "ERROR", db.lastError().text());
        a.exit();
    }
}
