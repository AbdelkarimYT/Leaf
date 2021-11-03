#ifndef CASH_MODEL_H
#define CASH_MODEL_H

#include <QSqlRelationalTableModel>

namespace Model { class Cash; }

class Cash : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "cash";

    enum Columns { id, user_id, operation_type, amount, date, description };

private:
    QSqlRelation hasOneUser;

public:
    explicit Cash(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~Cash();
};

#endif // CASH_MODEL_H
