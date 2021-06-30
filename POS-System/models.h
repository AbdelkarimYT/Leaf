#ifndef MODELS_H
#define MODELS_H

#include <QtSql>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>


extern QSqlDatabase db;
extern QSqlTableModel *prodects;
extern QSqlTableModel *suppliers;
extern QSqlTableModel *customers;
extern QSqlTableModel *cashIn;
extern QSqlTableModel *cashOut;
extern QSqlTableModel *familys;
extern QSqlTableModel *categorys;
extern QSqlTableModel *orders;


#endif // MODELS_H
