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
                emit this->receive(data);
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
    void Broadcasting()
    {
        for(auto it:m_tcps)
        {
            it->write("");
        }
    }

signals:void receive(QString s);

private:
    QTcpServer *m_s;
    unsigned short port;
    unsigned short connect_num;

public slots:
};
