#pragma once
#include <QWidget>
#include "core.h"
#include "mypushbottom.h"
#include <QLabel>

class PlayScene : public QWidget
{
    Q_OBJECT
public:
    PlayScene(QWidget*parent= nullptr);
    QPushButton *begin_;
signals:void backSignal();

};