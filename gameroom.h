#ifndef GAMEROOM_H
#define GAMEROOM_H

#include <QWidget>
#include "TCP_server.h"
namespace Ui {
class GameRoom;
}

class GameRoom : public QWidget
{
    Q_OBJECT

public:
    explicit GameRoom(QWidget *parent = nullptr);
    ~GameRoom();

private:
    Ui::GameRoom *ui;
    TCP_server *server;
};

#endif // GAMEROOM_H
