#ifndef BIGTABLE_H
#define BIGTABLE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "rule.h"
#include "ai.h"


namespace Ui {
class BigTable;
}

class BigTable : public QWidget
{
    Q_OBJECT

public:
    explicit BigTable(QWidget *parent = 0,int playerRole = 1,int gameMode = 0);
    ~BigTable();
    void begin();

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    Ui::BigTable *ui;
    int chesser;//当前执棋者
    int player;//玩家
    QTimer timer;//计时器
    QTimer AITimer;//ai延时
    int time;//剩余时间
    int** chesses;//棋盘
    bool LastisOver;//对局结束标志位
    Rule plaerRule;
    int gameMode;
    AI *ai;
    void coutChesses();

private slots:
    void timeCountDown();
    void startNewRound(int _chesser);
    void dealChess(int _x, int _y);
    void AIMove();

signals:
    void myMove(int x, int y);
    void gameOver();


};

#endif // BIGTABLE_H
