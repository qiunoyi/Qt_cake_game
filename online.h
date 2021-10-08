#ifndef ONLINE_H
#define ONLINE_H

#include <QWidget>
#include "gameroom.h"
#include "TCP_server.h"
#include "TCP_client.h"
#include "joinscene.h"
#include <QPainter>
//我这里大小写好像出了点问题，类最好大写，我就将就的写了，后面才发现,而且最好改成OnlineScene
namespace Ui {
class online;
}

class online : public QWidget
{
    Q_OBJECT

public:
    explicit online(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    ~online();

signals:
    void backSignal();
private slots:
    void on_create_room_clicked();

    void on_GoBackBtn_clicked();

    void on_quick_join_clicked();

private:
    Ui::online *ui;
    GameRoom *room;
    JoinScene *jscene;
};

#endif // ONLINE_H
