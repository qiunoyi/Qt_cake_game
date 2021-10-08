#pragma once
#include <QWidget>
#include "core.h"
#include "mypushbottom.h"
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QPalette>
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
    void paintEvent(QPaintEvent*);
signals:void backSignal();
void game_end();
};