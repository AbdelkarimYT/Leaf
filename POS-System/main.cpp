#include "mainwindow.h"
#include "logindialog.h"
#include "models.h"

#include <QApplication>
#include <QSettings>
#include <QSplashScreen>
#include <QPixmap>
#include <QMessageBox>

QSqlDatabase   db;
QSqlTableModel *prodects;
QSqlTableModel *customers;
QSqlTableModel *suppliers;
QSqlTableModel *cashIn;
QSqlTableModel *cashOut;
QSqlTableModel *familys;
QSqlTableModel *categorys;
QSqlTableModel *orders;
QSqlTableModel *users;

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
    db.setDatabaseName("pypos");

    if (db.open())
    {
        if (!d.exec())
            return 0;

        prodects  = new QSqlTableModel(nullptr, db);
        users     = new QSqlTableModel(nullptr, db);
        customers = new QSqlTableModel(nullptr, db);
        suppliers = new QSqlTableModel(nullptr, db);
        cashIn    = new QSqlTableModel(nullptr, db);
        cashOut   = new QSqlTableModel(nullptr, db);
        familys   = new QSqlTableModel(nullptr, db);
        categorys = new QSqlTableModel(nullptr, db);
        orders    = new QSqlTableModel(nullptr, db);

        prodects->setTable("prodects");
        users->setTable("users");
        customers->setTable("customers");
        suppliers->setTable("suppliers");
        cashIn->setTable("cash_in");
        cashOut->setTable("cash_out");
        familys->setTable("familys");
        categorys->setTable("categorys");
        orders->setTable("orders");

        prodects->select();
        users->select();
        customers->select();
        suppliers->select();
        familys->select();
        categorys->select();
        cashIn->select();
        cashOut->select();
        orders->select();

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
