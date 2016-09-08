#include <QCoreApplication>
#ifndef CONN_H
#define CONN_H
#include <QObject>
#include <QTcpSocket>
#include "message.h"

typedef struct {
    std::string returnString;
    bool        shouldSend;
} Return;

class Conn : public QObject {
    Q_OBJECT
public:
//    explicit Conn();
    Conn(std::string, std::string, uint, Return(*f)(Message&));
    int Send(std::string);
public slots:
    void Read();
private:
    Return(*ret)(Message&);
    std::string botname,Cookie;
    QTcpSocket *socket;
    std::string Recieve();
};

#endif // CONN_H
