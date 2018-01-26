#include "bigtable.h"
#include "ui_bigtable.h"
#include <QDebug>
#include <QMessageBox>
#define white 1
#define black 2

BigTable::BigTable(QWidget *parent, int playerRole, int gameMode) :
    QWidget(parent),
    ui(new Ui::BigTable)
{
    ui->setupUi(this);
    //初始化
    chesses = new int*[8];
    for(int i = 0;i<8;i++)
    {
        chesses[i] = new int[8];
    }

    for(int i = 0;i<8;i++)
    {
        for(int j = 0;j<8;j++)
        {
            chesses[i][j] = 0;
        }
    }
    chesses[3][3] = white;
    chesses[4][3] = black;
    chesses[3][4] = black;
    chesses[4][4] = white;

    player = playerRole;

    ui->chessWidget->setChesses(chesses);
    ui->chessWidget->update();

    LastisOver = false;

    plaerRule.setChesses(chesses);

    this->gameMode = gameMode;
    ai = new AI(6);

    connect(&timer,&QTimer::timeout,this,&BigTable::timeCountDown);
    connect(ui->chessWidget,&ChessTable::chessPoint,this,[&](int _x,int _y)
    {
        if(player != chesser)
            return;
        dealChess(_x,_y);
    });
    connect(&AITimer,&QTimer::timeout,this,&BigTable::AIMove);
}

BigTable::~BigTable()
{
    delete ui;
    for(int i = 0;i<8;i++)
    {
        delete[] chesses[i];
    }
    delete[] chesses;
}

void BigTable::begin()
{
    startNewRound(black);
}

void BigTable::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap(":/new/prefix1/image/Frame.jpg"));
}

void BigTable::coutChesses()
{
    int countWhite = 0;
    int countBlack = 0;
    bool chesserOver = true;
    for(int i = 0;i < 8; ++i)
    {
        for(int j = 0;j < 8;j++)
        {
            if(chesses[i][j] == white)
            {
                ++countWhite;
            }
            else if(chesses[i][j] == black)
            {
                ++countBlack;
            }
            else
            {
                if(plaerRule.placeChess(i,j,chesser,false)>0)
                    chesserOver = false;
            }
        }
    }
    ui->lcdNumberBCount->display(countBlack);
    ui->lcdNumberWCount->display(countWhite);
    if(chesserOver)
    {
        if(LastisOver)
        {
            if(timer.isActive())
                timer.stop();
            if(AITimer.isActive())
                AITimer.stop();
            QMessageBox::information(this,"消息","对局结束！");
            emit gameOver();
            this->close();
            return;
        }
        LastisOver = true;
        startNewRound(chesser = white?black:white);
    }
    LastisOver = false;
}

void BigTable::timeCountDown()
{
    time--;
    ui->lcdNumberCount->display(time);
    if(0==time)
    {
        int next = chesser==white?black:white;
        startNewRound(next);
    }
}

void BigTable::startNewRound(int _chesser)
{
    if(timer.isActive())
        timer.stop();
    chesser = _chesser;
    ui->chessWidget->setChessType(chesser);
    this->time = 30;
    QString str = player == chesser?"我方":"对方";
    QString str2;
    if(chesser == white)
    {
        str2 = str+"白子下";
        ui->labelPix->setPixmap(QPixmap(":/new/prefix1/image/white.png"));
    }
    else
    {
        str2 = str+"黑子下";
        ui->labelPix->setPixmap(QPixmap(":/new/prefix1/image/black.png"));
    }
    ui->lableCount->setText(str2);
    if(!timer.isActive())
        timer.start(1000);    
    if(0 == gameMode&&chesser!=player)
    {
        if(!AITimer.isActive())
            AITimer.start(1500);
    }
    coutChesses();
}

void BigTable::dealChess(int _x, int _y)
{
    int ret = plaerRule.placeChess(_x,_y,chesser);
    if(ret >0 )
    {       
        ui->chessWidget->setLastAct(_x,_y);
        ui->chessWidget->update();
        if(chesser == player)
            emit myMove(_x,_y);
        startNewRound(chesser == white?black:white);
    }
}

void BigTable::AIMove()
{
    if(chesser == player)
        return;
    int x,y;
    ai->setAIRole(chesser);
    ai->setCurrentTable(chesses);
    ai->action(x,y);
    dealChess(x,y);
    if(AITimer.isActive())
        AITimer.stop();
}



