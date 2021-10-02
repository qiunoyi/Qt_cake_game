#include "playscene.h"
PlayScene::PlayScene(QWidget*parent): QWidget(parent)
{
    //界面还没生成
    game *gamer=new game;
    gamer->dice();
    gamer->judge();
    int rank=gamer->get_rank();
    QString rank_name=gamer->get_rank_name();
    qDebug()<<rank<<endl;
    //qDebug()<<rank_name<<std::endl;好像不支持QString格式
}