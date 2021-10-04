#include "gameroom.h"
#include "ui_gameroom.h"

GameRoom::GameRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameRoom)
{
    ui->setupUi(this);
    server=new TCP_server;
    server->listen();
    connect(server,&TCP_server::receive,this,[=](QString s){
        ui->CMsg->append(s);
    });
}

GameRoom::~GameRoom()
{
    delete ui;
}

void GameRoom::on_beginBtn_clicked()
{
    for(auto &it:server->m_tcps)
    {
        server->send(it,"begin_game");
    }
    emit this->begingame();
    onlinegame=new OnlinePlay;
    this->hide();
    onlinegame->show();
}

