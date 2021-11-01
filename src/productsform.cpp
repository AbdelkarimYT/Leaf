#include "productsform.h"
#include "ui_productsform.h"

extern ProductModel *products;

ProductsForm::ProductsForm(QWidget *parent) : QWidget(parent), ui(new Ui::ProductsForm)
{
    ui->setupUi(this);
    ui->productsTableView->setModel(products);
    ui->productsTableView->horizontalHeader()->moveSection(ProductModel::Columns::category_id, ProductModel::Columns::price);
}

ProductsForm::~ProductsForm()
{
    delete ui;
}
