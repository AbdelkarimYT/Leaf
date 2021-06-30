#include "chashform.h"
#include "ui_chashform.h"
#include "models.h"

ChashForm::ChashForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChashForm)
{
    ui->setupUi(this);
    ui->chashInTabel->setModel(cashIn);
    ui->chashOutTabel->setModel(cashOut);
}

ChashForm::~ChashForm()
{
    delete ui;
}
