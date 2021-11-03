#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

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

    void on_actionInventory_triggered();

    void on_actionHome_triggered();

    void on_actionSupplier_triggered();

    void on_actionSupplierPayments_triggered();

    void on_actionCustomerPayments_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAIN_WINDOW_H
