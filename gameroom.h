#ifndef GAMEROOM_H
#define GAMEROOM_H

#include <QWidget>
#include "TCP_server.h"
#include "onlineplay.h"
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
};

#endif // GAMEROOM_H
