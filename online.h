#ifndef ONLINE_H
#define ONLINE_H

#include <QWidget>
#include "gameroom.h"
//我这里大小写好像出了点问题，类最好大写，我就将就的写了，后面才发现,而且最好改成OnlineScene
namespace Ui {
class online;
}

class online : public QWidget
{
    Q_OBJECT

public:
    explicit online(QWidget *parent = nullptr);
    ~online();

private slots:
    void on_create_room_clicked();

private:
    Ui::online *ui;
};

#endif // ONLINE_H
