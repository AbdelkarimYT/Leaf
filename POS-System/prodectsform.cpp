#include "prodectsform.h"
#include "ui_prodectsform.h"
#include "models.h"

ProdectsForm::ProdectsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProdectsForm)
{
    ui->setupUi(this);
    ui->familysTable->setModel(familys);
    ui->categorysTable->setModel(categorys);
    ui->prodectsTabel->setModel(prodects);
}

ProdectsForm::~ProdectsForm()
{
    delete ui;
}
