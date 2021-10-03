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
    room->show();
}


void online::on_GoBackBtn_clicked()
{
    emit this->backSignal();
}


void online::on_quick_join_clicked()
{
    jscene=new JoinScene;
    jscene->show();
}

