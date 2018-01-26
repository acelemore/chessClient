#include "cregister.h"
#include "ui_cregister.h"
#include <QMessageBox>
#include "unity.h"

cRegister::cRegister(QWidget *parent, network *net) :
    QDialog(parent),
    ui(new Ui::cRegister)
{
    ui->setupUi(this);
    this->net = net;
}

cRegister::~cRegister()
{
    delete ui;
}

void cRegister::on_pushButton_clicked()
{
    if(ui->lePsw->text()!=ui->leCfPsw->text())
    {
        QMessageBox::information(this,"错误","两次输入的密码不一致！");
        return;
    }
    QString name = ui->leUsr->text();
    QString pass = ui->lePsw->text();

    QString rec = net->sendMsg(QString("cmd=register;name=%1;pass=%2;").arg(name).arg(pass));
    myDebug<<rec;
    QString res = chessGetValue(rec,"cmd");
    myDebug<<res;
    if(res == "ok")
    {
        QMessageBox::information(this,"提示","注册成功！");
        this->close();
    }
    else
    {
        QString reason = chessGetValue(rec,"reason");
        if(reason.indexOf("already exsits")!=-1)
        {
            QMessageBox::information(this,"错误","该用户已存在！");
            return;
        }
        else
        {
            QMessageBox::information(this,"错误",reason);
            return;
        }
    }
}
