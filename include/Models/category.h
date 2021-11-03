#ifndef CATEGORY_MODEL_H
#define CATEGORY_MODEL_H

#include <QSqlTableModel>

namespace Model { class Category; }

class Category : public QSqlTableModel
{
    Q_OBJECT

public:
    inline static const QString Table = "categorys";

    enum Columns { id, family_id, name };

public:
    explicit Category(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase());
    ~Category();
};

#endif // CATEGORY_MODEL_H
