#pragma once
#include "playscene.h"

class OnlinePlay : public PlayScene
{
    Q_OBJECT
public:
    explicit OnlinePlay(QWidget*parent=nullptr);
    QPushButton *chatBtn;
signals:
    void get_key();

   
};
