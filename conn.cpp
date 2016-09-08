#include "conn.h"
#include "message.h"
#include <iostream>

Conn::Conn(std::string p_botname, std::string serveraddress, uint port, Return (*f)(Message&)){
    ret = f;
    socket = new QTcpSocket(this);
    socket->connectToHost (QString::fromStdString (serveraddress), quint16(port));
    if(socket->waitForConnected(3000)){
      qDebug() << "Connected to chatPi Server!!";
    } else {
      qDebug() << "conn.cpp - Error : Check whether the server is up and running";
    }


    connect(socket, SIGNAL(readyRead()), this, SLOT(Read()));
    //connect(parent, SLOT(printGotData), this )
    botname = p_botname;
    Send("JOIN " + botname + " botpassword");
}

int Conn::Send(std::string message) {
    return socket->write((message+"\n").c_str ());
}

void Conn::Read(){
    std::string message = socket->readAll ().toStdString ();
    Message temp(message);
    if (temp.GetFrom () == "*ChatPi*") {
        if (temp.GetType () == "cookie") {
            Cookie = temp.GetContent ();
        } else {
            std::cout << "Message from *ChatPi* of type ";
            std::cout << temp.GetType ();
            std::cout << " : " << temp.GetContent () << std::endl;
        }
        return;
    }
    if (temp.GetFrom () == botname) {
        return;
    }
    Return a = (*ret)(temp);
    if (a.shouldSend) {
        if (temp.GetChannel () == "broadcast") {
            message = "BROADCAST WITH " + Cookie + " " + a.returnString;
        } else {
            message = "MSG WITH " + Cookie + " TO " + temp.GetFrom () + " " + a.returnString;
        }
         if (Send(message) == -1) {
             std::cout << "Unable to connect to the server" << std::endl;
         }
    }
}
