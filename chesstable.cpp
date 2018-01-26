#include "chesstable.h"
#include "ui_chesstable.h"
#include <QDebug>
#include <QPoint>

ChessTable::ChessTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChessTable)
{
    ui->setupUi(this);
    chesses = NULL;
}

ChessTable::~ChessTable()
{
    delete ui;
}

void ChessTable::setChessType(int _type)
{
    chessType = _type;
}

void ChessTable::setChesses(int** &_chesses)
{
    chesses = _chesses;
}

void ChessTable::setLastAct(int _x, int _y)
{
    chessX = _x;
    chessY = _y;
}


void ChessTable::paintEvent(QPaintEvent *)//绘图，绘图区域为正方形
{    
    paintLenth = __min(this->width(),this->height());//取长宽值中的最小值为绘图区域长度
    paintX = (this->width()-paintLenth)/2;//确定绘图区域起点
    paintY = (this->height()-paintLenth)/2;

    QPainter painter(this);//绘制背景
    painter.drawPixmap(paintX,paintY,paintLenth,paintLenth,QPixmap(":/new/prefix1/TIM截图20171109183131.png"));

    QPen pen;
    pen.setWidth(5);

    painter.setPen(pen);

    int x = paintX+2.5;
    int y = paintY+2.5;

    QRectF square(x,y,paintLenth-5,paintLenth-5);//绘制表格边框
    painter.drawRect(square);

    spaceX = (paintLenth-2.5)/8;//计算格子间距
    spaceY = (paintLenth-2.5)/8;



    for(int i = 0;i<7;i++)//绘制表格线条
    {
        x = x+spaceX;
        y = y+spaceY;

        painter.drawLine(x,paintY+2.5,x,paintY+paintLenth-5);
        painter.drawLine(paintX+2.5,y,paintX+paintLenth-5,y);
    }

    if(NULL == chesses)
        return;

    for(int i = 0;i<8;i++)//遍历数组，绘制棋子
    {
        for(int j = 0;j<8;j++)
        {
            switch (chesses[i][j]) {
            case 1:
                painter.drawPixmap(paintX+spaceX*i+10,paintY+spaceY*j+10,spaceX-15,spaceY-15,QPixmap(":/new/prefix1/image/white.png"));
                break;
            case 2:
                painter.drawPixmap(paintX+spaceX*i+10,paintY+spaceY*j+10,spaceX-15,spaceY-15,QPixmap(":/new/prefix1/image/black.png"));
            default:
                break;
            }
        }
    }
    if(chessX>-1&&chessY>-1)//绘制最后一次落棋的边框
    {
        QRectF squareS(paintX+spaceX*chessX+6.25,paintY+spaceY*chessY+6.25,spaceX-7.5,spaceY-7.5);
        pen.setWidth(5);
        pen.setColor(Qt::green);
        painter.setPen(pen);
        painter.drawRect(squareS);
    }
}

void ChessTable::mousePressEvent(QMouseEvent *event)
{
    if(event->button()!=Qt::LeftButton)
        return;
    int actX = event->x() - paintX;
    int actY = event->y() - paintY;
    int nChessX = actX/spaceX;
    int nChessY = actY/spaceY;
    if(nChessX>-1&&nChessX<8&&nChessY>-1&&nChessY<8)
    {
        if(chesses[nChessX][nChessY] == 0)
            emit chessPoint(nChessX,nChessY);
    }
}



