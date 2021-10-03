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
    });
}

JoinScene::~JoinScene()
{
    delete ui;
}
