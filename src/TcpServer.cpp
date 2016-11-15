/*
 * Copyright (C) 2016 EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

/**
 * @file TcpServer.cpp
 * @brief QML wrapper source for QTcpServer
 * @author Ayberk Özgür
 * @date 2016-11-10
 */

#include "TcpServer.h"

TcpServer::TcpServer(QQuickItem* parent):
    QQuickItem(parent),
    server(this)
{
    host = "0:0:0:0";
    port = 0;
        connect(&server, SIGNAL(incomingConnectionSignal(qintptr)), this, SLOT(publishIncomingConnection(qintptr)));
}

TcpServer::~TcpServer(){}

bool TcpServer::isListening() const{
    return server.isListening();
}

void TcpServer::setListening(bool enable){
    bool wasListening = server.isListening();

    if(enable){
        if(!server.listen(QHostAddress(host), port))
            qWarning() << "TcpServer::setListening(): Couldn't start listening: " << server.errorString();
    }
    else
        server.close();

    if(wasListening != server.isListening())
        emit listeningChanged();
}

void TcpServer::setHost(QString host){
    if(host != this->host){
        bool wasListening = isListening();
        setListening(false);
        this->host = host;
        if(wasListening)
            setListening(true);
        emit hostChanged();
    }
}

void TcpServer::setPort(int port){
    if(port < 0){
        qWarning() << "TcpServer::setPort(): port given was negative, setting to 0.";
        port = 0;
    }
    else if(port > 0xFFFF){
        qWarning() << "TcpServer::setPort(): port given was larger than 65535, setting to 65535.";
        port = 0xFFFF;
    }

    if(port != this->port){
        bool wasListening = isListening();
        setListening(false);
        this->port = port;
        if(wasListening)
            setListening(true);
        emit portChanged();
    }
}

void TcpServer::publishIncomingConnection(qintptr socketDescriptor){
   qDebug() << "******************NEW CONNECTION"; //<< qsocket->peerAddress().toString();
   QIntPtr* wrappedSocketDesc = new QIntPtr();
   wrappedSocketDesc->ptr = socketDescriptor;
   emit newConnection(wrappedSocketDesc);
}
