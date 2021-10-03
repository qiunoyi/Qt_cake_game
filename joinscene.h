#ifndef JOINSCENE_H
#define JOINSCENE_H

#include <QWidget>
#include "TCP_client.h"
namespace Ui {
class JoinScene;
}

class JoinScene : public QWidget
{
    Q_OBJECT

public:
    explicit JoinScene(QWidget *parent = nullptr);
    ~JoinScene();
private:
    Ui::JoinScene *ui;
    TCP_client *client;
};

#endif // JOINSCENE_H
