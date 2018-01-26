#include "network.h"

network::network(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(ChessServerIP,ChessServerPort);
    if(!socket->waitForConnected(3000))
    {
        myDebug<<socket->error();
    }
}

QString network::sendMsg(QString content)
{
    QString str = QString("%1|%2").arg((content.length()+5),4,10,QLatin1Char('0')).arg(content);
    socket->write(str.toLocal8Bit());
    if(!socket->waitForReadyRead(3000))
    {
        myDebug<<socket->error();        
        socket->disconnectFromHost();
        return "服务器响应超时";
    }
    QString recv = readRecv();
    return recv;
}


QString network::sendMsgNoReply(QString content)
{
    QString str = QString("%1|%2").arg((content.length()+5),4,10,QLatin1Char('0')).arg(content);
    socket->write(str.toLocal8Bit());
    return "";
}

void network::startListen()
{
    connect(socket,&QTcpSocket::readyRead,this,[&](){
        QString msg = readRecv();
        emit getMsg(msg);
    });
}

void network::stopListen()
{
    disconnect(socket,&QTcpSocket::readyRead,this,0);
}

QString network::readRecv()
{
    char buf[4096];
    memset(buf,0,sizeof(buf));
    int lenth = 0;
    while(lenth<4)
    {
        int res = socket->read(buf+lenth,4-lenth);
        lenth = lenth + res;
    }

    int msgLenth = (buf[0]-48)*1000+ (buf[1]-48)*100+ (buf[2]-48)*10+ (buf[3]-48)*1;

    while(lenth<msgLenth)
    {
        int res = socket->read(buf+lenth,msgLenth-lenth);
        lenth = lenth + res;
    }

    QString res(buf);
    return res;
}
