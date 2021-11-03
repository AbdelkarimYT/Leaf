#ifndef HOME_FORM_H
#define HOME_FORM_H

#include <QWidget>

namespace Ui { class HomeForm; }

class HomeForm : public QWidget
{
    Q_OBJECT

public:
    explicit HomeForm(QWidget *parent = nullptr);
    ~HomeForm();

private:
    Ui::HomeForm *ui;
};

#endif // HOME_FORM_H
