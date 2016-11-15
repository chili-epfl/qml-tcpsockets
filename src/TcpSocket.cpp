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
 * @file TcpSocket.cpp
 * @brief QML wrapper source for QTcpSocket
 * @author Ayberk Özgür
 * @date 2016-11-10
 */

#include "TcpSocket.h"

TcpSocket::TcpSocket(QQuickItem* parent):
    QQuickItem(parent),
    socket(this)
    //socketIsExternal(false)
{
    connect(&socket, SIGNAL(connected()), this, SIGNAL(connected()));
    connect(&socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(publish()));
}

/*TcpSocket::TcpSocket(qintptr socketDescriptor, QQuickItem* parent):
    TcpSocket(parent)
    //socketIsExternal(true)
{
    socket.setSocketDescriptor(socketDescriptor);
}*/

TcpSocket::~TcpSocket(){
    socket.flush();
}

void TcpSocket::publish(){
    QList<int> list;
    QByteArray receivedBytes = socket.readAll();

    qDebug() << "QDEBUG: " << receivedBytes;

    //for(char c : receivedBytes)
    //    list << (int)c;
    emit test();
    qDebug() << "PUB";
}

bool TcpSocket::writeBytes(QList<int> bytes){
    QByteArray container;
    for(int b : bytes){
        if(b < 0 || b > 0xFF){
            qWarning() << "TcpSocket::writeBytes(): bytes contain integer not in [0x00,0xFF], not writing";
            return false;
        }
        else
            container.append((char)b);
    }

    int numBytesToWrite = container.size();
    const char* bytesRaw = container.constData();
    while(numBytesToWrite > 0){
        int bytesWritten = socket.write(bytesRaw, numBytesToWrite);
        if(bytesWritten < 0){
            qWarning() << "TcpSocket::writeBytes(): Bytes were not written: " << socket.errorString();
            return false;
        }
        numBytesToWrite -= bytesWritten;
        bytesRaw += bytesWritten;
    }
    socket.flush();

    return true;
}








void TcpSocket::conn(QString host, int port){
    socket.connectToHost(host, port);
}
void TcpSocket::setSocketDesc(QIntPtr* wrappedSocketDesc){
    socket.setSocketDescriptor(wrappedSocketDesc->ptr);
    wrappedSocketDesc->deleteLater();
}
