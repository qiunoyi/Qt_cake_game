#include"onlineplay.h"
OnlinePlay::OnlinePlay()
{
    begin_->setDisabled(true);
    if(key)
    {
        begin_->setDisabled(false);
    }
}
