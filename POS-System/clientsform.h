#ifndef CLIENTSFORM_H
#define CLIENTSFORM_H

#include <QWidget>
#include <QMessageBox>

namespace Ui { class ClientsForm; }

class ClientsForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClientsForm(QWidget *parent = nullptr);
    ~ClientsForm();

private:
    Ui::ClientsForm *ui;
};

#endif // CLIENTSFORM_H
