#ifndef USER_MODEL_H
#define USER_MODEL_H

#include <QSqlTableModel>

namespace Model { class User; }

class User : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "users";

    enum Columns { id, name, username, password, created_at, updated_at };

public:
    explicit User(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~User();
};

#endif // USER_MODEL_H
