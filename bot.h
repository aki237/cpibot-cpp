#ifndef BOT_H
#define BOT_H
#include <QCoreApplication>
#include "conn.h"

class Bot : public QCoreApplication
{
private:
    Conn* connection;
public:
    Bot(int argc, char **argv, std::string, std::string, uint, Return(*f)(Message&));
};

#endif // BOT_H
