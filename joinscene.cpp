#include "joinscene.h"
#include "ui_joinscene.h"

JoinScene::JoinScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JoinScene)
{
    ui->setupUi(this);
}

JoinScene::~JoinScene()
{
    delete ui;
}
