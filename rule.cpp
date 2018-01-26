#include "rule.h"
#include <QList>
#include <QPoint>

Rule::Rule()
{

}

void Rule::setChesses(int **_chesses)
{
    chesses = _chesses;
}

int Rule::placeChess(int _x, int _y, int _chess, bool _change)
{
    int eatChess = 0;
    int X = _x;
    int Y = _y;
    QList<QPoint> eatList;
    QList<QPoint> eatAll;
    //左
    while(X>0)
    {
        --X;
        if(chesses[X][Y] == _chess)
        {
            eatAll.append(eatList);
            break;
        }
        else if( chesses[X][Y] == 0)
            break;
        else
        {
            eatList.append(QPoint(X,Y));
        }
    }
    eatList.clear();
    X = _x;
    Y = _y;
    //右
    while(X<7)
    {
        ++X;
        if(chesses[X][Y] == _chess)
        {
            eatAll.append(eatList);
            break;
        }
        else if( chesses[X][Y] == 0)
            break;
        else
        {
            eatList.append(QPoint(X,Y));
        }
    }
    eatList.clear();
    X = _x;
    Y = _y;
    //上
    while(Y>0)
    {
        --Y;
        if(chesses[X][Y] == _chess)
        {
            eatAll.append(eatList);
            break;
        }
        else if( chesses[X][Y] == 0)
            break;
        else
        {
            eatList.append(QPoint(X,Y));
        }
    }
    eatList.clear();
    X = _x;
    Y = _y;
    //下
    while(Y<7)
    {
        ++Y;
        if(chesses[X][Y] == _chess)
        {
            eatAll.append(eatList);
            break;
        }
        else if( chesses[X][Y] == 0)
            break;
        else
        {
            eatList.append(QPoint(X,Y));
        }
    }
    eatList.clear();
    X = _x;
    Y = _y;
    //左上
    while(X>0&&Y>0)
    {
        --X;
        --Y;
        if(chesses[X][Y] == _chess)
        {
            eatAll.append(eatList);
            break;
        }
        else if( chesses[X][Y] == 0)
            break;
        else
        {
            eatList.append(QPoint(X,Y));
        }
    }
    eatList.clear();
    X = _x;
    Y = _y;
    //右上
    while(X<7&&Y>0)
    {
        ++X;
        --Y;
        if(chesses[X][Y] == _chess)
        {
            eatAll.append(eatList);
            break;
        }
        else if( chesses[X][Y] == 0)
            break;
        else
        {
            eatList.append(QPoint(X,Y));
        }
    }
    eatList.clear();
    X = _x;
    Y = _y;
    //左下
    while(X>0&&Y<7)
    {
        --X;
        ++Y;
        if(chesses[X][Y] == _chess)
        {
            eatAll.append(eatList);
            break;
        }
        else if( chesses[X][Y] == 0)
            break;
        else
        {
            eatList.append(QPoint(X,Y));
        }
    }
    eatList.clear();
    X = _x;
    Y = _y;
    //右下
    while(X<7&&Y<7)
    {
        ++X;
        ++Y;
        if(chesses[X][Y] == _chess)
        {
            eatAll.append(eatList);
            break;
        }
        else if( chesses[X][Y] == 0)
            break;
        else
        {
            eatList.append(QPoint(X,Y));
        }
    }
    eatList.clear();
    X = _x;
    Y = _y;


    QPoint point;

    eatChess = eatAll.size();

    if(eatChess>0&&_change)
    {
        foreach (point, eatAll) {
            chesses[point.x()][point.y()] = _chess;
        }
        chesses[_x][_y] = _chess;
    }
    return eatChess;
}
