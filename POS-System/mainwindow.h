#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAddProduct_triggered();
    void on_actionAddFamily_triggered();
    void on_actionAddCategory_triggered();
    void on_actionAddUser_triggered();
    void on_actionAddClient_triggered();
    void on_sellingBtn_clicked();
    void on_prodectsBtn_clicked();
    void on_clientsBtn_clicked();
    void on_actionAddSupplier_triggered();
    void on_actionAddOrder_triggered();
    void on_cashBtn_clicked();

    void on_suppliersBtn_clicked();

    void on_ordersBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
