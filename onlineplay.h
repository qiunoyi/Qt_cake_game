#pragma once
#include "playscene.h"

class OnlinePlay : public PlayScene
{
    Q_OBJECT
public:
    OnlinePlay();
signals:
    void get_key();

   
};
