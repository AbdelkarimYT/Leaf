#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionUsers_triggered();

    void on_actionCash_triggered();

    void on_actionProducts_triggered();

    void on_actionFamilys_triggered();

    void on_actionCategorys_triggered();

    void on_actionCustomers_triggered();

    void on_actionCustomer_Payments_triggered();

    void on_actionSupplie_triggered();

    void on_actionInventory_triggered();

    void on_actionHome_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
