#pragma once
#include "playscene.h"

class OnlinePlay : public PlayScene
{
    Q_OBJECT
public:
    OnlinePlay();

signals:
    void backSignal();

private:
    bool key = 0;
};
