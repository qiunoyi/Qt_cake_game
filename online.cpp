#include "online.h"
#include "ui_online.h"

online::online(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::online)
{
    ui->setupUi(this);
    
}

online::~online()
{
    delete ui;
}

void online::on_create_room_clicked()
{
    room=new GameRoom();
    room->setGeometry(this->x()+65,this->y()+200,room->width(),room->height());
    connect(room,&GameRoom::begingame,this,[=](){this->hide();});
    room->show();
    connect(room,&GameRoom::backSignal,this,[=](){
        room->deleteLater();
        this->show();
    });
}


void online::on_GoBackBtn_clicked()
{
    emit this->backSignal();
}


void online::on_quick_join_clicked()
{
    jscene=new JoinScene;
    jscene->setGeometry(this->x()+65,this->y()+200,jscene->width(),jscene->height());
    connect(jscene,&JoinScene::begingame,this,[=](){this->hide();});
    jscene->show();
    connect(jscene,&JoinScene::backSignal,this,[=](){
        jscene->deleteLater();
        this->show();
    });
}

void online::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/background.jfif");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}


