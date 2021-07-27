#ifndef MODELS_H
#define MODELS_H

#include <QtSql>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include <QSqlDatabase>
#include <QSqlQuery>


extern QSqlDatabase db;
extern QSqlRelationalTableModel *products;
extern QSqlTableModel           *suppliers;
extern QSqlTableModel           *customers;
extern QSqlRelationalTableModel *cashIn;
extern QSqlTableModel           *cashOut;
extern QSqlTableModel           *familys;
extern QSqlTableModel           *categorys;
extern QSqlTableModel           *orders;
extern QSqlTableModel           *users;
extern QSqlRelationalTableModel *inventory;
extern QSqlRelationalTableModel *customerPayments;

#endif // MODELS_H
