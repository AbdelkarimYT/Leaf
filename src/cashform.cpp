#include "cashform.h"
#include "ui_cashform.h"

extern CashModel *cash;

CashForm::CashForm(QWidget *parent): QWidget(parent), ui(new Ui::CashForm)
{
    ui->setupUi(this);

    userIdDelegate = new QSqlRelationalDelegate(ui->cashTableView);
    amountDelegate = new QDoubleSpinBoxDelegate(ui->cashTableView);
    dateDelegate = new QDateTimeEditDelegate(ui->cashTableView);
    descriptionDelegate = new QPlainTextEditDelegate(ui->cashTableView);

    ui->cashTableView->setModel(cash);
    ui->cashTableView->setItemDelegateForColumn(CashModel::Columns::user_id, userIdDelegate);
    ui->cashTableView->setItemDelegateForColumn(CashModel::Columns::amount, amountDelegate);
    ui->cashTableView->setItemDelegateForColumn(CashModel::Columns::date, dateDelegate);
    ui->cashTableView->setItemDelegateForColumn(CashModel::Columns::description, descriptionDelegate);
    //ui->cashInTableView->hideColumn(CashInModel::columns::id);
    //ui->cashInTableView->horizontalHeader()->setSectionResizeMode(CashInModel::Columns::id, QHeaderView::ResizeToContents);
    //ui->cashInTableView->horizontalHeader()->setSectionResizeMode(CashInModel::Columns::user_id, QHeaderView::Stretch);
    //ui->cashInTableView->horizontalHeader()->setSectionResizeMode(CashInModel::Columns::amount, QHeaderView::ResizeToContents);
    //ui->cashInTableView->horizontalHeader()->setSectionResizeMode(CashInModel::Columns::date, QHeaderView::ResizeToContents);
    ui->cashTableView->horizontalHeader()->setSectionsMovable(true);
}

CashForm::~CashForm()
{
    delete ui;
    delete userIdDelegate;
    delete amountDelegate;
    delete dateDelegate;
    delete descriptionDelegate;
}
