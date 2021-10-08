#pragma once
#include "playscene.h"

class OnlinePlay : public PlayScene
{
    Q_OBJECT
public:
    OnlinePlay();
    QPushButton *chat;
signals:
    void get_key();

   
};
