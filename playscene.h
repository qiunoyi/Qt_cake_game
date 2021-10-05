#pragma once
#include <QWidget>
#include "core.h"
#include "mypushbottom.h"
#include <QLabel>

class PlayScene : public QWidget
{
    Q_OBJECT
public:
    QString rank_name;
    QString points;
    PlayScene(QWidget*parent= nullptr);
    QPushButton *begin_;
    QLabel *cur_user;
    QLabel *result;
signals:void backSignal();
void game_end();
};