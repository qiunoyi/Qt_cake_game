#include "playscene.h"
PlayScene::PlayScene(QWidget*parent): QWidget(parent)
{
    
    setFixedSize(320,588);
    begin_=new QPushButton(this);
    begin_->move(this->width()*0.5-begin_->width()*0.5,this->height()*0.7);
    begin_->setText("博饼");
    QLabel *result=new QLabel(this);
    result->setFixedSize(160,40);
    result->setText("这是一张图");
    result->move(this->width()*0.5-result->width()*0.5,this->height()*0.5);
    
    QPushButton *goBack=new QPushButton(this);
    goBack->move(this->width()*0.5-goBack->width()*0.5,this->height()*0.6);
    goBack->setText("返回");

    connect(begin_,&QPushButton::clicked,this,[=](){
    game *gamer=new game;
    gamer->dice();
    gamer->judge();
    int rank=gamer->get_rank();
    QString rank_name=gamer->get_rank_name();
    QString points=gamer->get_points();
    result->setText(points+rank_name);
    qDebug("points = %s\n",qPrintable(points));
    qDebug()<<rank<<endl;
    delete gamer;
    emit this->game_end();
    });
    
    connect(goBack,&QPushButton::clicked,this,[=](){
    emit this->backSignal();
    });
    
}