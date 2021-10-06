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
    connect(jscene,&JoinScene::begingame,this,[=](){this->hide();});
    jscene->show();
    connect(jscene,&JoinScene::backSignal,this,[=](){
        jscene->deleteLater();
        this->show();
    });
}

