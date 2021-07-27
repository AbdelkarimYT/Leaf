#include "productsform.h"
#include "ui_productsform.h"
#include "models.h"

productsForm::productsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::productsForm)
{
    ui->setupUi(this);

    productRelationalDelegate = new QSqlRelationalDelegate(nullptr);
    familyFilterModel = new QSortFilterProxyModel();

    familyFilterModel->setSourceModel(familys);
    familyFilterModel->setFilterCaseSensitivity(Qt::CaseSensitive);
    familyFilterModel->setFilterKeyColumn(-1);

    ui->familysTable->setModel(familyFilterModel);
    ui->categorysTable->setModel(categorys);
    ui->productsTabel->setModel(products);
    ui->productsTabel->setItemDelegate(productRelationalDelegate);
}

productsForm::~productsForm()
{
    delete ui;
    delete productRelationalDelegate;
    delete familyFilterModel;
}


void productsForm::on_familySearch_textChanged(const QString &arg1)
{
    familyFilterModel->setFilterFixedString(arg1);
}

