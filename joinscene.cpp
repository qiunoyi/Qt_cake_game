#include "joinscene.h"
#include "ui_joinscene.h"

JoinScene::JoinScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JoinScene)
{
    ui->setupUi(this);
    ui->roomIP->setText("127.0.0.1");
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QString ip=ui->roomIP->text();
        QString name=ui->userName->text();
        client= new TCP_client(ip,name,this);
        client->connect_Host();
        qDebug()<<"正在创建连接";
        client->send(name);
        connect(client,&TCP_client::begin_game,this,[=](){
            emit this->begingame();
            onlinegame=new OnlinePlay;
            onlinegame->setGeometry(this->x()-65,this->y()-200,onlinegame->width(),onlinegame->height());
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
            connect(client,&TCP_client::receive_key,this,[=](){
                emit onlinegame->get_key();
            });
            connect(client,&TCP_client::game_result,this,[=](QString name_,QString points_,QString rank_name_){
                onlinegame->cur_user->setText(name_);
                onlinegame->result->setText(points_+rank_name_);
            });
            //返回
            connect(onlinegame,&OnlinePlay::backSignal,this,[=](){
                onlinegame->close();
                onlinegame->deleteLater();
                emit this->backSignal();
            });
            connect(onlinegame,&OnlinePlay::chat_,this,[=](QString s){
                client->send("chat_"+client->name+'_'+s);
            });
        });
        
        
    });

}

JoinScene::~JoinScene()
{
    delete ui;
}
