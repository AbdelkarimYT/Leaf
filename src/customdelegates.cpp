#include "customdelegates.h"


QDoubleSpinBoxDelegate::QDoubleSpinBoxDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
}

QDoubleSpinBoxDelegate::~QDoubleSpinBoxDelegate()
{
}

QWidget *QDoubleSpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(0.00);
    editor->setSuffix(" DA");
    return editor;
}

void QDoubleSpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    double value = index.model()->data(index, Qt::EditRole).toDouble();
    QDoubleSpinBox *widget = static_cast<QDoubleSpinBox *>(editor);
    widget->setValue(value);
}

void QDoubleSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *widget = static_cast<QDoubleSpinBox*>(editor);
    widget->interpretText();
    double value = widget->value();
    model->setData(index, value, Qt::EditRole);
}

void QDoubleSpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

/*************************************/
QDateTimeEditDelegate::QDateTimeEditDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QDateTimeEditDelegate::~QDateTimeEditDelegate()
{
}

QWidget *QDateTimeEditDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDateTimeEdit *editor = new QDateTimeEdit(parent);
    editor->setDisplayFormat("yyyy/MM/dd hh:mm:ss AP");
    editor->setCalendarPopup(true);
    return editor;
}

void QDateTimeEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDateTime value = QDateTime::fromString(index.model()->data(index, Qt::EditRole).toString(), "yyyy/MM/dd hh:mm:ss AP");
    QDateTimeEdit *widget = static_cast<QDateTimeEdit *>(editor);
    widget->setDateTime(value);
}

void QDateTimeEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateTimeEdit *widget = static_cast<QDateTimeEdit*>(editor);
    widget->interpretText();
    QString value = widget->dateTime().toString("yyyy/MM/dd hh:mm:ss AP");
    model->setData(index, value, Qt::EditRole);
}

void QDateTimeEditDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

/******************************************************************************/

QPlainTextEditDelegate::QPlainTextEditDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
}

QPlainTextEditDelegate::~QPlainTextEditDelegate()
{
}

QWidget *QPlainTextEditDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QPlainTextEdit *descriptionEditor = new QPlainTextEdit(parent);
    descriptionEditor->setMinimumHeight(150);
    descriptionEditor->setLineWrapMode(QPlainTextEdit::NoWrap);
    return descriptionEditor;
}

void QPlainTextEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();
    QPlainTextEdit *widget = static_cast<QPlainTextEdit *>(editor);
    widget->setPlainText(value);
}

void QPlainTextEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    // TODO
}

void QPlainTextEditDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
