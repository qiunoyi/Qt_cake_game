#include "gameroom.h"
#include "ui_gameroom.h"

GameRoom::GameRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameRoom)
{
    ui->setupUi(this);
}

GameRoom::~GameRoom()
{
    delete ui;
}
