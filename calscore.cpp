#include "calscore.h"

CalScore::CalScore()
{

}

void CalScore::cal(int **_table, int &_whiteScore, int &_blackScore)
{
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(_table[i][j]!=0)
            {
                if(_table[i][j] == 1)
                {
                    _whiteScore+=scoreTable[i][j];
                }
                else
                {
                    _blackScore+=scoreTable[i][j];
                }

            }
        }
    }
}
