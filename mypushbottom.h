#pragma once
#include<QPushButton>
#include<QMainWindow>
#include<QString>
#include<QPixmap>
#include<QDebug>
#include<QPropertyAnimation>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QString,QString="",QWidget *parent = nullptr);
    QString normalImg,pressImg;
    void zoom1();
    void zoom2();
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
signals:

};

