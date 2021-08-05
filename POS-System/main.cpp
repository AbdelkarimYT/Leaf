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
QSqlRelationalTableModel *customerPayments;

int main(int argc, char *argv[])
{
    QApplication  a(argc, argv);
    QSplashScreen splash(QPixmap(":/Backgrounds/res/splash.jpg"));

    splash.setWindowFlags(Qt::WindowStaysOnTopHint | Qt::SplashScreen);
    splash.showMessage("Launching...", Qt::AlignBottom, Qt::white);
    splash.show();
    //a.setStyle("Fusion");

    LoginDialog d(&splash);
    MainWindow  w;
    QSettings   settings("settings.ini", QSettings::IniFormat);

    splash.showMessage("Connecting to database...", Qt::BottomLeftCorner, Qt::white);

    db = QSqlDatabase::addDatabase(settings.value("/DatabaseConfiguration/Driver").toString());
    db.setHostName(settings.value("/DatabaseConfiguration/HostName").toString());
    db.setPort(settings.value("/DatabaseConfiguration/Port").toInt());
    db.setUserName(settings.value("/DatabaseConfiguration/Username").toString());
    db.setPassword(settings.value("/DatabaseConfiguration/Password").toString());
    db.setDatabaseName(settings.value("/DatabaseConfiguration/DatabaseName").toString());

    if (db.open())
    {
        splash.showMessage("Login...", Qt::AlignBottom, Qt::white);

        if (!d.exec()) return 0;

        splash.showMessage("Loading data from database...", Qt::AlignBottom, Qt::white);

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
        customerPayments = new QSqlRelationalTableModel(nullptr, db);

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
        customerPayments->setTable("customer_payments");

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
        customerPayments->setHeaderData(0, Qt::Horizontal, "#");
        customerPayments->setHeaderData(1, Qt::Horizontal, "User Name");
        customerPayments->setHeaderData(2, Qt::Horizontal, "Client Name");
        customerPayments->setHeaderData(3, Qt::Horizontal, "Invoice Number");
        customerPayments->setHeaderData(4, Qt::Horizontal, "Paid Amount");
        customerPayments->setHeaderData(5, Qt::Horizontal, "Change Amount");
        customerPayments->setHeaderData(6, Qt::Horizontal, "Transaction Date");

        products->setRelation(1, QSqlRelation("familys", "id", "name"));
        products->setRelation(2, QSqlRelation("categorys", "id", "name"));
        inventory->setRelation(1, QSqlRelation("products", "id", "name"));
        cashIn->setRelation(1, QSqlRelation("users", "id", "name"));
        customerPayments->setRelation(1, QSqlRelation("uses", "id", "name"));
        customerPayments->setRelation(2, QSqlRelation("customers", "id", "name"));
        customerPayments->setRelation(3, QSqlRelation("customer_bills", "id", "name"));

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
        customerPayments->select();

        splash.showMessage("Starting...", Qt::AlignBottom, Qt::white);

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
