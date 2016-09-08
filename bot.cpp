#include "bot.h"

Bot::Bot(int argc, char** argv, std::string botname, std::string serveraddress, uint port, Return(*f)(Message &))
    : QCoreApplication(argc,argv)
{
    connection = new Conn(botname,serveraddress,port,f);
}
