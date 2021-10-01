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
    void connect()
    {
        m_tcp = new QTcpSocket(this);
        m_tcp->connectToHost(QHostAddress(ip), port);
        
    }

private:
    QTcpSocket *m_tcp;
    unsigned short port;
    QString ip;
public slots:
};