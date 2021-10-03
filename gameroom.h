#ifndef GAMEROOM_H
#define GAMEROOM_H

#include <QWidget>

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
};

#endif // GAMEROOM_H
