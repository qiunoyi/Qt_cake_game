#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QtCore>
#include "playscene.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent*);

private:
    Ui::Widget *ui;
    PlayScene *local_play;
};
#endif // WIDGET_H
