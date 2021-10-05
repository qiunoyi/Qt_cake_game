#include "joinscene.h"
#include "ui_joinscene.h"

JoinScene::JoinScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JoinScene)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QString ip=ui->roomIP->text();
        QString name=ui->userName->text();
        client= new TCP_client(ip,name);
        client->connect_Host();
        qDebug()<<"正在创建连接";
        client->send(name);
        connect(client,&TCP_client::begin_game,this,[=](){
            emit this->begingame();
            onlinegame=new OnlinePlay;
            onlinegame->show();
            this->hide();
            connect(onlinegame,&OnlinePlay::game_end,this,[=](){
                qDebug()<<"收到onlineplay发来的消息";
                client->send_result(client->name,onlinegame->points,onlinegame->rank_name);
                //延迟1s
                QTimer::singleShot(1000,this,[=]{
                    client->send("game_end");
                });
            });
        });
        connect(client,&TCP_client::receive_key,this,[=](){
            emit onlinegame->get_key();
        });
        
    });

}

JoinScene::~JoinScene()
{
    delete ui;
}
