#include "clobby.h"
#include "ui_clobby.h"
#include "unity.h"
#include <QMessageBox>
#include <QThread>

cLobby::cLobby(QWidget *parent, network* net, QString token,QString player) :
    QWidget(parent),
    ui(new Ui::cLobby)
{
    ui->setupUi(this);
    this->net = net;
    this->token = token;
    this->player = player;
    ui->pushButton_4->setEnabled(false);
}

cLobby::~cLobby()
{
    delete ui;
}


void cLobby::on_pushButton_3_clicked()
{
    refresh();
}

void cLobby::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString opponent = item->text();
    QString rec = net->sendMsg(QString("cmd=match;player=%1;opponent=%2;token=%3;").arg(player).arg(opponent).arg(token));
    this->setEnabled(false);
    net->startListen();
    connect(net,&network::getMsg,this,[&](QString msg){
        myDebug<<msg;
        if(chessGetValue(msg,"cmd")=="ack")
        {
            net->stopListen();
            disconnect(net,0,this,0);
            if(chessGetValue(msg,"what")=="matchAccapted")
            {
                QMessageBox::information(this,"消息","对方已接受");
                startARound(1);
                this->setEnabled(false);
            }
            else
                QMessageBox::information(this,"消息","对方已拒绝");
            this->setEnabled(true);
        }
    });
}

void cLobby::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(true);
    QString rec = net->sendMsg(QString("cmd=ready;player=%1;token=%2;").arg(player).arg(token));
    net->startListen();
    connect(net,&network::getMsg,this,[&](QString msg){
        if(chessGetValue(msg,"cmd")=="ask")
        {
            if(chessGetValue(msg,"what")=="newMatch")
            {int choice = QMessageBox::question(this,"信息","已匹配到玩家，是否接受？");
                if(choice == QMessageBox::Yes)
                {
                    net->stopListen();
                    net->sendMsg(QString("cmd=ack;what=ok;token=%1").arg(token));
                    disconnect(net,0,this,0);
                    startARound(2);
                    this->setEnabled(false);
                }
                else
                {
                     net->stopListen();
                     net->sendMsg(QString("cmd=ack;what=denied;token=%1").arg(token));
                     disconnect(net,0,this,0);
                }
            }
        }
    });
}

void cLobby::dealMsg(QString msg)
{
    myDebug<<msg;
    if(chessGetValue(msg,"cmd") == "go")
    {
        game->begin();
    }

    if(chessGetValue(msg,"cmd") == "move")
    {
        QString posX = chessGetValue(msg,"posX");
        QString posY = chessGetValue(msg,"posY");
        emit opponmentMove(posX.toInt(),posY.toInt());
    }

}

void cLobby::refresh()
{
    ui->listWidget->clear();
    QString rec = net->sendMsg(QString("cmd=refresh;token=%1;player=%2").arg(token).arg(player));
    if(chessGetValue(rec,"cmd")=="ok")
    {
        QString players = chessGetValue(rec,"players");
        QStringList playerList = players.split(',',QString::SkipEmptyParts);
        ui->listWidget->addItems(playerList);
    }
    else
    {
        QMessageBox::information(this,"错误",chessGetValue(rec,"reason"));
    }
}

void cLobby::startARound(int role)
{
    game = new BigTable(0,role,1);
    game->setAttribute(Qt::WA_DeleteOnClose);
    game->show();
    QThread::msleep(100);
    QString rec = net->sendMsg(QString("cmd=undefined;player=%1;token=%2").arg(player).arg(token));
    myDebug<<rec;
    net->startListen();
    connect(net,SIGNAL(getMsg(QString)),this,SLOT(dealMsg(QString)));
    connect(this,SIGNAL(opponmentMove(int,int)),game,SLOT(dealChess(int,int)));
    connect(game,&BigTable::myMove,this,[&](int x,int y){
        net->sendMsgNoReply(QString("cmd=move;player=%1;token=%2;posX=%3;posY=%4").arg(player).arg(token).arg(x).arg(y));
    });
    connect(game,&BigTable::destroyed,this,[&](){
        net->sendMsgNoReply(QString("cmd=end;"));
        this->setEnabled(true);
        net->stopListen();
        disconnect(net,0,this,0);
        on_pushButton_4_clicked();
    });
}

void cLobby::on_pushButton_4_clicked()
{
    net->stopListen();
    net->sendMsg(QString("cmd=deReady;player=%1;token=%2;").arg(player).arg(token));
    disconnect(net,0,this,0);
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(false);
}
