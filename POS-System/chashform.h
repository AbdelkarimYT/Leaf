#ifndef CHASHFORM_H
#define CHASHFORM_H

#include <QWidget>

namespace Ui { class ChashForm; }

class ChashForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChashForm(QWidget *parent = nullptr);
    ~ChashForm();

private:
    Ui::ChashForm *ui;
};

#endif // CHASHFORM_H
