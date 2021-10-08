#pragma once
#include "playscene.h"
#include "tasknamebox.h"
class OnlinePlay : public PlayScene
{
    Q_OBJECT
public:
    explicit OnlinePlay(QWidget*parent=nullptr);
    QPushButton *chatBtn;
    TaskNameBox *tnb;
signals:
    void get_key();
    void chat_(QString chatContent);
   
};
