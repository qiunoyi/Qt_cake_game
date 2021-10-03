#ifndef ONLINE_H
#define ONLINE_H

#include <QWidget>
#include "gameroom.h"
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
