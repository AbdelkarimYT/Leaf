#ifndef MONY_DELEGATE_H
#define MONY_DELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QDoubleSpinBox>

class MonyDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit MonyDelegate(QObject *parent = nullptr);
    ~MonyDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // MONY_DELEGATE_H
