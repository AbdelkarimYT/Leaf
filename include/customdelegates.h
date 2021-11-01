#ifndef CUSTOM_DELEGATES_H
#define CUSTOM_DELEGATES_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QSqlRelationalDelegate>
#include <QDoubleSpinBox>
#include <QDateTimeEdit>
#include <QPlainTextEdit>

namespace CustomDelegates
{
    class QDoubleSpinBoxDelegate;
    class QDateTimeEditDelegate;
    class QPlainTextEditDelegate;
}

class QDoubleSpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit QDoubleSpinBoxDelegate(QObject *parent = nullptr);
    ~QDoubleSpinBoxDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};


class QDateTimeEditDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit QDateTimeEditDelegate(QObject *parent = nullptr);
    ~QDateTimeEditDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};


class QPlainTextEditDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit QPlainTextEditDelegate(QObject *parent = nullptr);
    ~QPlainTextEditDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // CUSTOM_DELEGATES_H
