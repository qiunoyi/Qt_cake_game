#include "mypushbottom.h"

MyPushButton::MyPushButton(QString normal,QString press,QWidget *parent) :
    QPushButton(parent),normalImg(normal),pressImg(press)
{
    QPixmap pic;
    bool ret = pic.load(normalImg);
    if(!ret) qDebug()<<"加载失败";
    setFixedSize(pic.width(),pic.height());
    setIcon(pic);
    setIconSize(QSize(pic.width(),pic.height()));
    setStyleSheet("QPushButton{border:0px}");

}
void MyPushButton::zoom1()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");//创建对象,几何形的一个范围
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));//设置起始位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));//设置终止位置
    animation->setDuration(200);//设置时间间隔
    animation->setEasingCurve(QEasingCurve::OutBounce);//设置动画效果,缓和曲线的弹跳效果
    animation->start();//开始动画
}
void MyPushButton::zoom2()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");//创建对象,几何形的一个范围
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));//设置起始位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));//设置终止位置
    animation->setDuration(200);//设置时间间隔
    animation->setEasingCurve(QEasingCurve::OutBounce);//设置动画效果,缓和曲线的弹跳效果
    animation->start();//开始动画
}
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(pressImg!="")
    {
        QPixmap pic;
        pic.load(pressImg);
        setFixedSize(pic.width(),pic.height());
        setIcon(pic);
        setIconSize(QSize(pic.width(),pic.height()));
        setStyleSheet("QPushButton{border:0px}");

    }
    return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(pressImg!="")
    {
        QPixmap pic;
        pic.load(normalImg);
        setFixedSize(pic.width(),pic.height());
        setIcon(pic);
        setIconSize(QSize(pic.width(),pic.height()));
        setStyleSheet("QPushButton{border:0px}");
    }
    return QPushButton::mouseReleaseEvent(e);
}