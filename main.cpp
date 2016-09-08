#include "bot.h"

Return helloWorldProcess(Message& m) {
    Return ret;
    ret.shouldSend = true;
    ret.returnString = "Hello, " + m.GetFrom ();
    return ret;
}

int main(int argc, char *argv[])
{
    Bot a(argc,argv,"sample_bot","192.168.0.100",6672,helloWorldProcess);
    return a.exec();
}
