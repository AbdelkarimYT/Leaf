#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->content->setCurrentWidget(ui->homePage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionUsers_triggered()
{
    ui->content->setCurrentWidget(ui->usersPage);
}


void MainWindow::on_actionCash_triggered()
{
    ui->content->setCurrentWidget(ui->cashPage);
}

void MainWindow::on_actionProducts_triggered()
{
    ui->content->setCurrentWidget(ui->productsPage);
}


void MainWindow::on_actionFamilys_triggered()
{
}


void MainWindow::on_actionCategorys_triggered()
{
}


void MainWindow::on_actionCustomers_triggered()
{
    ui->content->setCurrentWidget(ui->customersPage);
}


void MainWindow::on_actionSupplier_triggered()
{
    ui->content->setCurrentWidget(ui->suppliesPage);
}


void MainWindow::on_actionInventory_triggered()
{
    ui->content->setCurrentWidget(ui->inventoryPage);
}


void MainWindow::on_actionHome_triggered()
{
    ui->content->setCurrentWidget(ui->homePage);
}


void MainWindow::on_actionSupplierPayments_triggered()
{
    ui->content->setCurrentWidget(ui->supplierPaymentsPage);
}


void MainWindow::on_actionCustomerPayments_triggered()
{
    ui->content->setCurrentWidget(ui->customerPaymentsPage);
}

