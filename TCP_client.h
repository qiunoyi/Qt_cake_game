#pragma once
#include <QTcpSocket>
#include <QObject>
#include <QHostAddress>
class TCP_client : public QObject
{
    Q_OBJECT
public:
    QString name;
    TCP_client(QString i,QString n,QObject *parent=nullptr) :  QObject(parent),ip(i),name(n)
    {
        //默认端口8848
        port=8848;
    }
    void connect_Host()
    {
        m_tcp = new QTcpSocket(this);
        m_tcp->connectToHost(QHostAddress(ip), port);
        //接受的数据可以有不同的模式之后override一下receive
        connect(m_tcp,&QTcpSocket::readyRead,this,[=]()
        {
            auto data=m_tcp->readAll();
            if(data=="current_key") 
            {
                qDebug()<<"得到key";
                emit this->receive_key();
            }
            else if(data=="begin_game") 
            {
                qDebug()<<"开始游戏";
                emit this->begin_game();
            }
            else if(data.startsWith("game_result"))
            {
                qDebug()<<data;
                int index1=data.indexOf('\n',0);
                int index2=data.indexOf('\n',index1+1);
                int index3=data.indexOf('\n',index2+1);
                auto name=data.mid(index1+1,index2-index1-1);
                auto points=data.mid(index2+1,index3-index2-1);
                auto rank_name=data.mid(index3+1);
                emit this->game_result(name,points,rank_name);
            }
            else 
            {
                qDebug()<<"收到一般信息";
                emit this->receive(data);
            }
        });
        connect(m_tcp, &QTcpSocket::disconnected, this, [=]() 
        {
            m_tcp->close();
            m_tcp->deleteLater();
        });
    }
    void send(QString s)
    {
        //这里加一条判断是否已经连接的语句
        m_tcp->write(s.toUtf8());
        //.......
    }
    void send_result(QString name,QString points,QString rank_name)
    {
        m_tcp->write(("game_result\n"+name+'\n'+points+'\n'+rank_name).toUtf8());
    }
signals:void receive(QString s);
        void receive_key();
        void begin_game();
        void game_result(QString name,QString points,QString rank_name);
private:
    QTcpSocket *m_tcp;
    unsigned short port;
    QString ip;

public slots:
};