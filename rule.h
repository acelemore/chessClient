#ifndef RULE_H
#define RULE_H


class Rule
{
public:
    Rule();
    void setChesses(int** _chesses);
    int placeChess(int _x,int _y,int _chess,bool _change = true);

private:
    int** chesses;

};

#endif // RULE_H
