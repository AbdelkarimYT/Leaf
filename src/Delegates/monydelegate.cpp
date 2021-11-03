#include "monydelegate.h"

MonyDelegate::MonyDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    // TODO
}

MonyDelegate::~MonyDelegate()
{
    // TODO
}

QWidget *MonyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(0.00);
    editor->setSuffix(" DA");
    return editor;
}

void MonyDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    double value = index.model()->data(index, Qt::EditRole).toDouble();
    QDoubleSpinBox *widget = static_cast<QDoubleSpinBox *>(editor);
    widget->setValue(value);
}

void MonyDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *widget = static_cast<QDoubleSpinBox*>(editor);
    widget->interpretText();
    double value = widget->value();
    model->setData(index, value, Qt::EditRole);
}

void MonyDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
