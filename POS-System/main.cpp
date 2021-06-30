#include "mainwindow.h"
#include "logindialog.h"
#include "models.h"

#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QMessageBox>

QSqlDatabase db;
QSqlTableModel *prodects;
QSqlTableModel *customers;
QSqlTableModel *suppliers;
QSqlTableModel *cashIn;
QSqlTableModel *cashOut;
QSqlTableModel *familys;
QSqlTableModel *categorys;
QSqlTableModel *orders;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap(":/Backgrounds/res/splash.jpg"));
    LoginDialog d(nullptr);
    MainWindow w;

    //a.setStyle("Fusion");
    splash.show();

    db = QSqlDatabase::addDatabase("QMYSQL", "MainDbConnection");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("toor");
    db.setDatabaseName("pypos");

    if (db.open())
    {
        if (!d.exec())
            return 0;

        prodects = new QSqlTableModel(nullptr, db);
        customers = new QSqlTableModel(nullptr, db);
        suppliers = new QSqlTableModel(nullptr, db);
        cashIn = new QSqlTableModel(nullptr, db);
        cashOut = new QSqlTableModel(nullptr, db);
        familys = new QSqlTableModel(nullptr, db);
        categorys = new QSqlTableModel(nullptr, db);
        orders = new QSqlTableModel(nullptr, db);

        prodects->setTable("prodects");
        customers->setTable("customers");
        suppliers->setTable("suppliers");
        cashIn->setTable("cash_in");
        cashOut->setTable("cash_out");
        familys->setTable("familys");
        categorys->setTable("categorys");
        orders->setTable("orders");

        prodects->select();
        customers->select();
        suppliers->select();
        familys->select();
        categorys->select();
        cashIn->select();
        cashOut->select();
        orders->select();

        MainWindow w;
        w.showMaximized();
        splash.finish(&w);
        db.close();
        return a.exec();
    }
    else
    {
        QMessageBox::critical(nullptr, "ERROR", db.lastError().text());
        a.exit();
    }
}
