#ifndef AI_H
#define AI_H
#include "rule.h"
#include"calscore.h"


class AI
{
public:
    AI(int _dif);
    ~AI();
    void setAIRole(int _role);
    void setCurrentTable(int** _table);
    void action(int& _x,int& _y);
    void setDifficult(int _dif);

private:
    int*** Tables;
    int AIRole;
    int playerRole;
    int difficulty;
    CalScore cal;
    Rule AIStep;
    Rule simStep;

    void initThisTable(int _this);
    int simActions(int _x,int _y,int _table);
};

#endif // AI_H
