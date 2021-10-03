#pragma once
#include <QWidget>
#include "core.h"
#include "mypushbottom.h"
#include <QLabel>
//这个类可以用ui界面重新写一下也可以不用，不用的话要规划一下界面布局
class PlayScene : public QWidget
{
    Q_OBJECT
public:
    PlayScene(QWidget*parent= nullptr);
signals:void backSignal();

};