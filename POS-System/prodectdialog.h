#ifndef PRODECTDIALOG_H
#define PRODECTDIALOG_H

#include <QDialog>
#include <QMenu>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QRandomGenerator64>

namespace Ui { class ProdectDialog; }

class ProdectDialog : public QDialog {

    Q_OBJECT

public:
    explicit ProdectDialog(QWidget *parent = nullptr);
    ~ProdectDialog();

private slots:
    void on_addFamilyButton_clicked();
    void on_addCategoryButton_clicked();
    void on_discount_valueChanged(double value);
    void on_discount_100_valueChanged(int value);
    void on_dialogButtons_accepted();
    void on_generateBarcodeButton_clicked();
    void on_addToListButton_clicked();
    void on_barcodesList_customContextMenuRequested(const QPoint &pos);
    void on_actionDeleteBarcode_triggered();
    void on_actionUpdateBarcode_triggered();

private:
    Ui::ProdectDialog *ui;
    QSqlQueryModel *familyMdoel;
    QSqlQueryModel *categoryModel;
};

#endif // PRODECTDIALOG_H
