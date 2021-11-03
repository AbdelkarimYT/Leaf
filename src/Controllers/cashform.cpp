#include "cashform.h"
#include "ui_cashform.h"

extern Cash *cash;

CashForm::CashForm(QWidget *parent): QWidget(parent), ui(new Ui::CashForm)
{
    ui->setupUi(this);

    userIdDelegate = new QSqlRelationalDelegate(ui->cashTableView);
    amountDelegate = new MonyDelegate(ui->cashTableView);
    dateDelegate = new DateTimeDelegate(ui->cashTableView);
    descriptionDelegate = new TextDelegate(ui->cashTableView);

    ui->cashTableView->setModel(cash);
    ui->cashTableView->setItemDelegateForColumn(Cash::Columns::user_id, userIdDelegate);
    ui->cashTableView->setItemDelegateForColumn(Cash::Columns::amount, amountDelegate);
    ui->cashTableView->setItemDelegateForColumn(Cash::Columns::date, dateDelegate);
    ui->cashTableView->setItemDelegateForColumn(Cash::Columns::description, descriptionDelegate);
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
