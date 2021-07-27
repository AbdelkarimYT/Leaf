#include "chashform.h"
#include "ui_chashform.h"
#include "models.h"

ChashForm::ChashForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChashForm)
{
    ui->setupUi(this);

    cashInRelationalDelegate = new QSqlRelationalDelegate();

    ui->chashInTabel->setModel(cashIn);
    ui->chashOutTabel->setModel(cashOut);
    ui->chashInTabel->setItemDelegate(cashInRelationalDelegate);
}

ChashForm::~ChashForm()
{
    delete ui;
    delete cashInRelationalDelegate;
}
