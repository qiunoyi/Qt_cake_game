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
    GameRoom *room=new GameRoom(this);
    this->show();

}

