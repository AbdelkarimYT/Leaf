#ifndef FAMILY_MODEL_H
#define FAMILY_MODEL_H

#include <QSqlTableModel>

namespace Model { class Family; }

class Family : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "familys";

    enum Columns { id, name };

public:
    explicit Family(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~Family();
};

#endif // FAMILY_MODEL_H
