#pragma once
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <vector>
#include <QString>
using namespace std;
//服务端的类封装
class TCP_server : public QObject
{
    Q_OBJECT
public:
    vector<QTcpSocket *> m_tcps;//这样有点不安全，时间紧迫
    unsigned short connect_num;
    TCP_server()
    {
        //默认端口号8848
        port=8848;
        m_s = new QTcpServer(this);
        connect_num = 0;
    }
    //监听函数
    void listen()
    {
        m_s->listen(QHostAddress::Any, port);
        connect(m_s, &QTcpServer::newConnection, this, [=]()
        {
            QTcpSocket *temp = m_s->nextPendingConnection();
            qDebug()<<"已连接"<<endl;
            m_tcps.push_back(temp);
            ++connect_num;
            //接受的数据可以有不同的模式之后override一下receive
            connect(temp, &QTcpSocket::readyRead, this, [=]()
            {
                auto data=temp->readAll();
                if(data=="game_end")
                {
                    qDebug()<<"客户端游戏结束";
                    emit this->game_end();
                }
                else if(data.startsWith("game_result"))
                {
                    int index1=data.indexOf('\n',0);
                    int index2=data.indexOf('\n',index1+1);
                    int index3=data.indexOf('\n',index2+1);
                    auto name=data.mid(index1+1,index2-index1-1);
                    auto points=data.mid(index2+1,index3-index2-1);
                    auto rank_name=data.mid(index3+1);
                    qDebug()<<name;
                    qDebug()<<points;
                    qDebug()<<rank_name;
                    emit this->game_result(name,points,rank_name);
                }
                else emit this->receive(data);
            });
            connect(temp, &QTcpSocket::disconnected, this, [=, &temp]()
            {
                m_tcps.erase(find(m_tcps.begin(),m_tcps.end(),temp));
                temp->close();
                temp->deleteLater();
                temp=nullptr;
                --connect_num;          
            });

        });
    }
    //数据传输函数 这里定义需要的操作
    void send(QTcpSocket *tcp,QString s)
    {
        tcp->write(s.toUtf8());
        //.......
    }
    void Broadcasting(QString s)
    {
        for(auto it:m_tcps)
        {
            it->write(s.toUtf8());
        }
    }

signals:void receive(QString s);
        void game_end();
        void game_result(QString name,QString points,QString rank_name);

private:
    QTcpServer *m_s;
    unsigned short port;
    

public slots:
};
