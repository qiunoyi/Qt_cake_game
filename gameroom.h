#ifndef GAMEROOM_H
#define GAMEROOM_H

#include <QWidget>
#include "TCP_server.h"
#include "onlineplay.h"
#include <QTimer>
namespace Ui {
class GameRoom;
}

class GameRoom : public QWidget
{
    Q_OBJECT

public:
    explicit GameRoom(QWidget *parent = nullptr);
    ~GameRoom();
signals:void begingame();
private slots:
    void on_beginBtn_clicked();

private:
    Ui::GameRoom *ui;
    TCP_server *server;
    OnlinePlay *onlinegame;
    int key_cur=1;
};

#endif // GAMEROOM_H
