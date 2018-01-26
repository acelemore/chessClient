#ifndef CHESSTABLE_H
#define CHESSTABLE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QRectF>
#include <QMouseEvent>

namespace Ui {
class ChessTable;
}

class ChessTable : public QWidget
{
    Q_OBJECT

public:
    explicit ChessTable(QWidget *parent = 0);
    ~ChessTable();
    void setChessType(int _type);//设置执棋者
    void setChesses(int **&_chesses);
    void setLastAct(int _x,int _y);

signals:
    void chessPoint(int _x,int _y);

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *event);

private:
    Ui::ChessTable *ui;
    double paintX;
    double paintY;
    double paintLenth;

    double spaceX;
    double spaceY;
    int** chesses;
    int chessType;
    int chessX;
    int chessY;

private:
};

#endif // CHESSTABLE_H
