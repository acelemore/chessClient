#include "ai.h"
#include <QDebug>

AI::AI(int _dif)
{
    difficulty = _dif;
    Tables = new int**[difficulty];
    for(int i=0;i<difficulty;++i)
    {
        Tables[i] = new int*[8];
        for(int j=0;j<8;++j)
        {
            Tables[i][j] = new int[8];
        }
    }
}

AI::~AI()
{
    if(Tables!=NULL)
    {
        for(int i=0;i<difficulty;++i)
        {
            for(int j=0;j<8;++j)
            {
                delete[] Tables[i][j];
            }
            delete[] Tables[i];
        }
        delete[] Tables;
        Tables = NULL;
    }
}

void AI::setAIRole(int _role)
{
    AIRole = _role;
    playerRole = AIRole == 1?2:1;
}

void AI::setCurrentTable(int **_table)
{
    for(int i = 0;i < 8; ++i)
    {
        for(int j = 0;j < 8;++j)
        {
            Tables[0][i][j] = _table[i][j];
        }
    }
}

void AI::action(int &_x, int &_y)
{
    int x = 0;
    int y = 0;
    int maxScore = -1999;
    AIStep.setChesses(Tables[0]);
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(Tables[0][i][j] ==0 )
            {
                if(AIStep.placeChess(i,j,AIRole,false)>0)
                {
                    int score = simActions(i,j,1);
                    if(score>maxScore)
                    {
                        x = i;
                        y = j;
                        maxScore = score;
                    }
                }
            }
        }
    }
    _x = x;
    _y = y;
    qDebug()<<"max score = "<<maxScore;
}

void AI::setDifficult(int _dif)
{
    difficulty = _dif;
    qDebug()<<difficulty;


    Tables = new int**[difficulty];
    for(int i=0;i<difficulty;++i)
    {
        Tables[i] = new int*[8];
        for(int j=0;j<8;++j)
        {
            Tables[i][j] = new int[8];
        }
    }
    memset(Tables,0,sizeof(int)*64*difficulty);

}

void AI::initThisTable(int _this)
{
    int thisTable = _this;
    int lastTable = _this-1;
    for(int i =0; i < 8;++i)
    {
        for(int j = 0;j < 8; ++j)
        {
            Tables[thisTable][i][j] = Tables[lastTable][i][j];
        }
    }
}

int AI::simActions(int _x, int _y, int _table)//递归预测
{
    initThisTable(_table);
    int currentRole = _table%2!=0?AIRole:playerRole;
    simStep.setChesses(Tables[_table]);
    simStep.placeChess(_x,_y,currentRole,true);
    int whiteScore = 0;
    int blackScore = 0;
    cal.cal(Tables[_table],whiteScore,blackScore);
    int maxScore = 0;
    if(currentRole == 1)
    {
        maxScore = whiteScore - blackScore;
    }
    else
    {
        maxScore = blackScore - whiteScore;
    }

    if(_table < difficulty-1) //递归停止条件
    {
        initThisTable(_table+1);
        simStep.setChesses(Tables[_table+1]);
        simStep.placeChess(_x,_y,currentRole,true);

        currentRole = currentRole==AIRole?playerRole:AIRole;
        int maxScore2 = -2;

        for(int i = 0; i<8 ; ++i)
        {
            for(int j = 0; j< 8;++j)
            {
                if(Tables[_table][i][j] == 0)
                {
                    if(simStep.placeChess(i,j,currentRole,false)>0)
                    {
                        int score = simActions(i,j,_table+1);
                        if(score > maxScore2)
                        {
                            maxScore2 = score;
                        }
                    }
                }
            }
        }
        maxScore -= maxScore2;
    }
    return maxScore;
}



