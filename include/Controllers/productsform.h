#ifndef PRODUCTS_FORM_H
#define PRODUCTS_FORM_H

#include <QWidget>
#include <Product>

namespace Ui { class ProductsForm; }

class ProductsForm : public QWidget
{
    Q_OBJECT

public:
    enum { Products, Familys, Categorys };

public:
    explicit ProductsForm(QWidget *parent = nullptr);
    ~ProductsForm();

private:
    Ui::ProductsForm *ui;
};

#endif // PRODUCTS_FORM_H
