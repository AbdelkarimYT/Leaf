#ifndef TEXT_DELEGATE_H
#define TEXT_DELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QPlainTextEdit>

class TextDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit TextDelegate(QObject *parent = nullptr);
    ~TextDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // TEXT_DELEGATE_H
