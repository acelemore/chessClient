#ifndef UNITY_H
#define UNITY_H
#include <QDebug>
#include <QString>
#define myDebug qDebug()
#define ChessServerIP "192.168.17.128"
#define ChessServerPort 8888


static QString chessGetValue(QString source,QString key)
{
    int index1 = source.indexOf(QString("%1=").arg(key));
    int index2 = source.indexOf(";",index1);
    if(index2 == -1)index2 = source.length();
    int start = index1+key.length()+1;
    int lenth = index2 - start;
    return source.mid(start,lenth);
}

#endif // UNITY_H
