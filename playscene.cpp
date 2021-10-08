#include "playscene.h"
PlayScene::PlayScene(QWidget*parent): QWidget(parent)
{
    
    setFixedSize(400,660);
    begin_=new QPushButton(this);
    begin_->move(this->width()*0.5-begin_->width()*0.5,this->height()*0.7);
    begin_->setText("博饼");
    result=new QLabel(this);
    result->setFixedSize(240,60);
    result->setFont(QFont("Microsoft YaHei",16,75));
    result->setText("        博饼结果");
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::red);
    result->setPalette(pe);
    result->move(this->width()*0.5-result->width()*0.5,this->height()*0.45);

    //当前用户标签
    cur_user=new QLabel(this);
    cur_user->setText("local");
    cur_user->setFixedSize(240,60);
    cur_user->setFont(QFont("Microsoft YaHei",16,50));
    cur_user->move(0,0);

    QPushButton *goBack=new QPushButton(this);
    goBack->move(this->width()*0.5-goBack->width()*0.5,this->height()*0.6);
    goBack->setText("返回");

    connect(begin_,&QPushButton::clicked,this,[=](){
    game *gamer=new game;
    gamer->dice();
    gamer->judge();
    int rank=gamer->get_rank();
    rank_name=gamer->get_rank_name();
    points=gamer->get_points();
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

void PlayScene::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/background.jfif");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}