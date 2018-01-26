#ifndef CALSCORE_H
#define CALSCORE_H
#include <QPoint>
#include <QList>


class CalScore
{
public:
    CalScore();
    void cal(int **_table, int &_whiteScore, int &_blackScore);
    int scoreWhite;
    int scoreBlack;

private:

    int scoreTable[8][8] ={     //得分表
    {90,-60,10,10,10,10,-60,90},
    {-60,-80,5,5,5,5,-80,-60},
    {10,5,1,1,1,1,5,10},
    {10,5,1,1,1,1,5,10},
    {10,5,1,1,1,1,5,10},
    {10,5,1,1,1,1,5,10},
    {-60,-80,5,5,5,5,-80,-60},
    {90,-60,10,10,10,10,-60,90},
    };

};

#endif // CALSCORE_H
