#include "widget.h"
#include "./ui_widget.h"
#include "mypushbottom.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyPushButton *localGameBtn=new MyPushButton(":/res/local_game_b.jfif","",this);
    localGameBtn->move(this->width()*0.5-localGameBtn->width()*0.5,this->height()*0.7);
    connect(localGameBtn,&MyPushButton::clicked,localGameBtn,[=]
    {
        localGameBtn->zoom1();
        localGameBtn->zoom2();
    });
    
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/background.jfif");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
