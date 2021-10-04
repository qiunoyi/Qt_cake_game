#include"onlineplay.h"
OnlinePlay::OnlinePlay()
{
    begin_->setDisabled(true);
    connect(this,&OnlinePlay::get_key,this,[=](){
        begin_->setDisabled(false);
    });

}
