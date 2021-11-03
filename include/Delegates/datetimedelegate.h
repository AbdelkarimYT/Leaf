#ifndef DATETIME_DELEGATE_H
#define DATETIME_DELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QDateTimeEdit>

class DateTimeDelegate: public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit DateTimeDelegate(QObject *parent = nullptr);
    ~DateTimeDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // DATETIME_DELEGATE_H
