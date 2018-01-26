#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "bigtable.h"
#include "network.h"
#include "clobby.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButtonBack_clicked();

    void on_pushButtonClose_clicked();


    void on_pushButton_4_clicked();

    void on_pbSinWhite_clicked();

    void on_pbSinBlack_clicked();

    void on_pbLogin_clicked();

    void on_pbReg_clicked();

private:
    Ui::MainWindow *ui;
    BigTable* singleRound;
    cLobby* lobby;
    network mChessNet;
    QString token;
};

#endif // MAINWINDOW_H
