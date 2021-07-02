#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prodectdialog.h"
#include "familydialog.h"
#include "categorydialog.h"
#include "userdialog.h"
#include "customerdialog.h"
#include "supplierdialog.h"
#include "orderdialog.h"
#include "ordersform.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Qt");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAddProduct_triggered()
{
    ProdectDialog pd(this);
    pd.exec();
}


void MainWindow::on_actionAddFamily_triggered()
{
    FamilyDialog d(this);
    d.exec();
}


void MainWindow::on_actionAddCategory_triggered()
{
    CategoryDialog d(this);
    d.exec();
}


void MainWindow::on_actionAddUser_triggered()
{
    UserDialog d(this);
    d.exec();
}


void MainWindow::on_actionAddClient_triggered()
{
    CustomerDialog d(this);
    d.exec();
}


void MainWindow::on_sellingBtn_clicked()
{
   ui->title->setText("Selling");
   ui->content->setCurrentWidget(ui->sellingPage);
}


void MainWindow::on_prodectsBtn_clicked()
{
    ui->title->setText("Prodects");
    ui->content->setCurrentWidget(ui->prodectsPage);
}


void MainWindow::on_clientsBtn_clicked()
{
    ui->title->setText("Clients");
    ui->content->setCurrentWidget(ui->clientsPage);
}


void MainWindow::on_actionAddSupplier_triggered()
{
    SupplierDialog d(this);
    d.exec();
}


void MainWindow::on_actionAddOrder_triggered()
{
    OrderDialog d(this);
    d.exec();
}

void MainWindow::on_cashBtn_clicked()
{
    ui->title->setText("Cash");
    ui->content->setCurrentWidget(ui->chashPage);
}


void MainWindow::on_suppliersBtn_clicked()
{
    ui->title->setText("Suppliers");
    ui->content->setCurrentWidget(ui->suppliersPage);
}


void MainWindow::on_ordersBtn_clicked()
{
    ui->title->setText("Orders");
    ui->content->setCurrentWidget(ui->ordersPage);
}


void MainWindow::on_usersBtn_clicked()
{
    ui->title->setText("Users");
    ui->content->setCurrentWidget(ui->usersPage);
}

