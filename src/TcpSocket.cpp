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

#include <QHostAddress>

namespace QMLTcpSockets{

TcpSocket::TcpSocket(QQuickItem* parent):
    QQuickItem(parent),
    socket(this)
{
    connect(&socket, SIGNAL(connected()), this, SIGNAL(connected()));
    connect(&socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
    connect(&socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(emitErrorAsInt(QAbstractSocket::SocketError)));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(publish()));
    peer = "";
    port = 0;
}

TcpSocket::TcpSocket(QIntPtr* socketDescriptor, QQuickItem* parent):
    TcpSocket(parent)
{
    socket.setSocketDescriptor(socketDescriptor->ptr);
    socketDescriptor->deleteLater();
    peer = socket.peerAddress().toString();
    port = socket.peerPort();
}

TcpSocket::~TcpSocket(){
    socket.flush();
}

void TcpSocket::setSocketDescriptor(QIntPtr* socketDescriptor){
    socket.flush();
    socket.disconnectFromHost();

    socket.setSocketDescriptor(socketDescriptor->ptr);
    socketDescriptor->deleteLater();

    QString peer = socket.peerAddress().toString();
    if(this->peer != peer){
        this->peer = peer;
        emit peerChanged();
    }

    quint16 port = socket.peerPort();
    if(this->port != port){
        this->port = port;
        emit portChanged();
    }

    emit connected();
}

void TcpSocket::setSocketOption(int option, QVariant value){
    socket.setSocketOption((QAbstractSocket::SocketOption)option, value);
}

void TcpSocket::setPeer(QString peer){
    if(peer != this->peer){
        if(socket.state() != TcpSocketEnums::UnconnectedState)
            qWarning() << "TcpSocket::setPeer(): Can only set peer while disconnected.";
        else{
            this->peer = peer;
            emit peerChanged();
        }
    }
}

void TcpSocket::setPort(int port){
    if(port < 0){
        qWarning() << "TcpSocket::setPort(): port given was negative, setting to 0.";
        port = 0;
    }
    else if(port > 0xFFFF){
        qWarning() << "TcpSocket::setPort(): port given was larger than 65535, setting to 65535.";
        port = 0xFFFF;
    }

    if(port != this->port){
        if(socket.state() != TcpSocketEnums::UnconnectedState)
            qWarning() << "TcpSocket::setPort(): Can only set port while disconnected.";
        else{
            this->port = port;
            emit portChanged();
        }
    }
}

void TcpSocket::connectToHost(){
    socket.connectToHost(peer, port);
}

void TcpSocket::disconnectFromHost(){
    socket.disconnectFromHost();
}

void TcpSocket::emitErrorAsInt(QAbstractSocket::SocketError socketError){
    emit error(socketError);
}

void TcpSocket::publish(){
    QList<int> list;
    QByteArray receivedBytes = socket.readAll();
    for(char c : receivedBytes)
        list << (int)(*((unsigned char*)(&c)));
    emit bytesReceived(list);
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

}
