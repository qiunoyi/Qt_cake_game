#include "widget.h"
#include "./ui_widget.h"
#include "mypushbottom.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyPushButton *localGameBtn=new MyPushButton(":/res/local_game_b.jfif","",this);
    localGameBtn->setIconSize(QSize(360,360));
    localGameBtn->move(this->width()*0.5-localGameBtn->width()*0.5,360);
    connect(localGameBtn,&MyPushButton::clicked,localGameBtn,[=]
    {
        local_play=new PlayScene;
        local_play->setGeometry(this->geometry());
        localGameBtn->zoom1();
        localGameBtn->zoom2();
        QTimer::singleShot(500,this,[=]{
            this->hide();
            local_play->show();
        });
        connect(local_play,&PlayScene::backSignal,this,[=](){
            this->show();
            local_play->close();
            local_play->deleteLater();
            });
        
    });
    MyPushButton *OnlineBtn=new MyPushButton(":/res/hall_b.jfif","",this);
    OnlineBtn->setIconSize(QSize(280,280));
    OnlineBtn->move(this->width()*0.5-OnlineBtn->width()*0.5,0);
    connect(OnlineBtn,&MyPushButton::clicked,OnlineBtn,[=](){
        online_play=new online;
        online_play->setGeometry(this->geometry());
        OnlineBtn->zoom1();
        OnlineBtn->zoom2();
        QTimer::singleShot(500,this,[=]{
            this->hide();
            online_play->show();
        });
        connect(online_play,&online::backSignal,this,[=](){
            this->show();
            online_play->close();
            online_play->deleteLater();
            });
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
