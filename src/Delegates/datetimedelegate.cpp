#include "datetimedelegate.h"

DateTimeDelegate::DateTimeDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    // TODO
}

DateTimeDelegate::~DateTimeDelegate()
{
    // TODO
}

QWidget *DateTimeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDateTimeEdit *editor = new QDateTimeEdit(parent);
    editor->setDisplayFormat("yyyy/MM/dd HH:mm:ss");
    editor->setCalendarPopup(true);
    return editor;
}

void DateTimeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDateTime value = QDateTime::fromString(index.model()->data(index, Qt::EditRole).toString(), "yyyy/MM/dd HH:mm:ss");
    QDateTimeEdit *widget = static_cast<QDateTimeEdit *>(editor);
    widget->setDateTime(value);
}

void DateTimeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateTimeEdit *widget = static_cast<QDateTimeEdit*>(editor);
    widget->interpretText();
    QString value = widget->dateTime().toString("yyyy/MM/dd HH:mm:ss");
    model->setData(index, value, Qt::EditRole);
}

void DateTimeDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
