#ifndef CREGISTER_H
#define CREGISTER_H

#include <QDialog>
#include "network.h"

namespace Ui {
class cRegister;
}

class cRegister : public QDialog
{
    Q_OBJECT

public:
    explicit cRegister(QWidget *parent = 0,network* net = NULL);
    ~cRegister();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cRegister *ui;
    network* net;
};

#endif // CREGISTER_H
