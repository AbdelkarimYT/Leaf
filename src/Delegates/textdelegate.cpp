#include "textdelegate.h"

TextDelegate::TextDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    // TODO
}

TextDelegate::~TextDelegate()
{
    // TODO
}

QWidget *TextDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QPlainTextEdit *descriptionEditor = new QPlainTextEdit(parent);
    descriptionEditor->setMinimumHeight(150);
    descriptionEditor->setLineWrapMode(QPlainTextEdit::NoWrap);
    return descriptionEditor;
}

void TextDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();
    QPlainTextEdit *widget = static_cast<QPlainTextEdit *>(editor);
    widget->setPlainText(value);
}

void TextDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    // TODO
}

void TextDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
