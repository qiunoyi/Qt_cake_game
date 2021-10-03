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
            m_tcps.push_back(temp);
            ++connect_num;
            read(temp);
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
    void read(QTcpSocket *tcp)
    {
        connect(tcp,&QTcpSocket::readyRead,this,[=]()
        {
            auto data=tcp->readAll();
            //......
        });
    }
    void send(QTcpSocket *tcp)
    {
        tcp->write("");
        //.......
    }
    void Broadcasting()
    {
        for(auto it:m_tcps)
        {
            it->write("");
        }
    }


private:
    QTcpServer *m_s;
    vector<QTcpSocket *> m_tcps;
    unsigned short port;
    unsigned short connect_num;

public slots:
};