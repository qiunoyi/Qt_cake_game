#ifndef JOINSCENE_H
#define JOINSCENE_H

#include <QWidget>
#include "TCP_client.h"
#include "onlineplay.h"
namespace Ui {
class JoinScene;
}

class JoinScene : public QWidget
{
    Q_OBJECT

public:
    explicit JoinScene(QWidget *parent = nullptr);
    ~JoinScene();
signals:void begingame();
private:
    Ui::JoinScene *ui;
    TCP_client *client;
    OnlinePlay *onlinegame;
};

#endif // JOINSCENE_H
