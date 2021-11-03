#include "productsform.h"
#include "ui_productsform.h"

extern Product *products;

ProductsForm::ProductsForm(QWidget *parent) : QWidget(parent), ui(new Ui::ProductsForm)
{
    ui->setupUi(this);
    ui->productsTableView->setModel(products);
    ui->productsTableView->horizontalHeader()->moveSection(Product::Columns::category_id, Product::Columns::price);
}

ProductsForm::~ProductsForm()
{
    delete ui;
}
