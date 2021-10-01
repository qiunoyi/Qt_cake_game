#pragma once
#include <QTcpSocket>
#include <QObject>
#include <QHostAddress>
class TCP_client : public QObject
{
    Q_OBJECT
public:
    TCP_client(unsigned short p, QString i) : port(p), ip(i)
    {
    }
    void connect_Host()
    {
        m_tcp = new QTcpSocket(this);
        m_tcp->connectToHost(QHostAddress(ip), port);
        connect(m_tcp, &QTcpSocket::disconnected, this, [=]() 
        {
            m_tcp->close();
            m_tcp->deleteLater();
        });
    }
    void send(QTcpSocket *tcp)
    {
        tcp->write("");
        //.......
    }
    void read(QTcpSocket *tcp)
    {
        connect(tcp,&QTcpSocket::readyRead,this,[=]()
        {
            auto data=tcp->readAll();
            //......
        });
    }
    

private:
    QTcpSocket *m_tcp;
    unsigned short port;
    QString ip;
public slots:
};