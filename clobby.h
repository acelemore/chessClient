#ifndef CLOBBY_H
#define CLOBBY_H

#include <QWidget>
#include "network.h"
#include <QListWidget>
#include "bigtable.h"

namespace Ui {
class cLobby;
}

class cLobby : public QWidget
{
    Q_OBJECT

public:
    explicit cLobby(QWidget *parent = 0, network* net = NULL, QString token = "", QString player = "");
    ~cLobby();


private slots:

    void on_pushButton_3_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void dealMsg(QString msg);

    void on_pushButton_4_clicked();

private:
    Ui::cLobby *ui;
    network* net;
    QString token;
    QString player;
    BigTable* game;
    void refresh();

    void startARound(int role);

signals:
    void opponmentMove(int,int);
};

#endif // CLOBBY_H
