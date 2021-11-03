#ifndef PRODUCTSFORM_H
#define PRODUCTSFORM_H

#include "customdelegates.h"

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

#endif // PRODUCTSFORM_H
