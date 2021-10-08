#include"onlineplay.h"
OnlinePlay::OnlinePlay(QWidget*parent): PlayScene(parent)
{
    begin_->setDisabled(true);
    connect(this,&OnlinePlay::get_key,this,[=](){
        begin_->setDisabled(false);
    });
    connect(this,&OnlinePlay::game_end,this,[=]()
    {
        begin_->setDisabled(true);
    });
    chatBtn=new QPushButton(this);
    chatBtn->move(this->width()*0.5-chatBtn->width()*0.5,this->height()*0.8);
    chatBtn->setText("聊天");
    connect(chatBtn,&QPushButton::clicked,this,[=]()
    {
        tnb=new TaskNameBox();
        tnb->setGeometry(this->x()+90,this->y()+290,175,40);
        tnb->show();
        connect(tnb,&TaskNameBox::inputComplete,this,[=](QString chatContent)
        {
            emit this->chat_(chatContent);
            tnb->close();
            tnb->deleteLater();
        });
    });
}
