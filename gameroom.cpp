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
    emit onlinegame->get_key();
    //要保证连接数大于1
    connect(onlinegame,&OnlinePlay::game_end,this,[=](){
        server->send(server->m_tcps.front(),"current_key");
    });
    connect(server,&TCP_server::game_end,this,[=](){
        qDebug()<<"收到服务端发来的游戏结束消息";
        if(key_cur<server->connect_num)
        {
            server->send(server->m_tcps[key_cur],"current_key");
            key_cur++;
        }
        else 
        {
            emit onlinegame->get_key();
            key_cur=1;
        }
    });
    connect(server,&TCP_server::game_result,this,[=](QString name_,QString points_,QString rank_name_){
        onlinegame->cur_user->setText(name_);
        onlinegame->result->setText(points_+rank_name_);
    });

}

