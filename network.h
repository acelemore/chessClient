#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include "unity.h"
#include <QtNetwork/QTcpSocket>

class network : public QObject
{
    Q_OBJECT
public:
    explicit network(QObject *parent = 0);
    QString sendMsg(QString content);
    void startListen();
    void stopListen();
    QString sendMsgNoReply(QString content);
signals:
    void getMsg(QString);

public slots:

private:
    QTcpSocket* socket;
    QString readRecv();

};

#endif // NETWORK_H
