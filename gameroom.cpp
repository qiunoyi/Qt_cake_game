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
