#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "network.h"
#include <QMessageBox>
#include "cregister.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    qDebug()<<"close...";
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonClose_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pbSinWhite_clicked()
{
    singleRound = new BigTable(0,1);
    singleRound->setAttribute(Qt::WA_DeleteOnClose);
    connect(singleRound,&BigTable::destroyed,this,[&](){
        this->setEnabled(true);
    });
    this->setEnabled(false);
    singleRound->show();
    singleRound->begin();
}

void MainWindow::on_pbSinBlack_clicked()
{
    singleRound = new BigTable(0,2);
    singleRound->setAttribute(Qt::WA_DeleteOnClose);
    connect(singleRound,&BigTable::destroyed,this,[&](){
        this->setEnabled(true);
    });
    this->setEnabled(false);
    singleRound->show();
    singleRound->begin();
}

void MainWindow::on_pbLogin_clicked()//登陆
{
    int ret = mChessNet.connectToServer();
    if(ret == -1)
    {
        QMessageBox::information(this,"错误","无法连接到服务器");
        return;
    }
RELOGIN:
    QString name = ui->leUsrName->text();
    QString pass = ui->lePasW->text();
    if(name.length() == 0|| pass.length() == 0)
    {
        QMessageBox::information(this,"错误","用户名或密码不能为空！");
        return;
    }
    QString rec = mChessNet.sendMsg(QString("cmd=login;name=%1;pass=%2;").arg(name).arg(pass));
    myDebug<<rec;
    QString res = chessGetValue(rec,"cmd");
    myDebug<<res;
    if(res == "ok")
    {
        QMessageBox::information(this,"信息","登陆成功！");
        token = chessGetValue(rec,"token");
        lobby = new cLobby(0,&mChessNet,token,name);
        lobby->setAttribute(Qt::WA_DeleteOnClose);
        lobby->show();
        this->setEnabled(false);
        connect(lobby,&cLobby::destroyed,this,[&](){
            this->setEnabled(true);
        });
    }
    else
    {
        QString reason = chessGetValue(rec,"reason");
        if(reason.indexOf("Duplicate entry")!=-1)
        {
            int choice = QMessageBox::question(this,"信息","该用户已登陆，是否强制下线？");
            if(choice == QMessageBox::Yes)
            {
                mChessNet.sendMsg(QString("cmd=kick;name=%1;pass=%2;").arg(name).arg(pass));
                goto RELOGIN;
            }
        }
        else if(reason == "No such user or wrong password")
        {
            QMessageBox::information(this,"错误","错误的用户名或密码");
        }
        else
        {
            QMessageBox::information(this,"错误",reason);
        }
    }
}

void MainWindow::on_pbReg_clicked()
{
    cRegister reg(this,&mChessNet);
    reg.exec();
}
