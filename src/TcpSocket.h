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
 * @file TcpSocket.h
 * @brief QML wrapper header for QTcpSocket
 * @author Ayberk Özgür
 * @date 2016-11-10
 */

#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QQuickItem>
#include <QTcpSocket>
#include <QList>

#include "QIntPtr.h"
#include "TcpSocketEnums.h"

namespace QMLTcpSockets{

/**
 * @brief QML wrapper for QTcpSocket
 *
 * Can be created from a native socket descriptor returned from a TcpServer incoming connection, or can connect to a peer on its own.
 * Due to the sandboxing of WinRT, cannot listen on nor connect to localhost sockets on this platform.
 */
class TcpSocket : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

    /** @brief Address to connect to, or address of the already open remote connection, default "" */
    Q_PROPERTY(QString peer READ getPeer WRITE setPeer NOTIFY peerChanged)

    /** @brief Port to connect to, or port of the already open remote connection , must be in [0,65535], default 0 */
    Q_PROPERTY(int port READ getPort WRITE setPort NOTIFY portChanged)

public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates a new TcpSocket with the given QML parent
     *
     * @param parent The QML parent
     */
    TcpSocket(QQuickItem* parent = 0);

    /**
     * @brief Creates a new TcpSocket with the given QML parent, calls socketDescriptor->deleteLater()
     *
     * @param socketDescriptor Descriptor to the external native socket that was opened outside this wrapper, calls deleteLater() on it in the end
     * @param parent The QML parent
     */
    TcpSocket(QMLTcpSockets::QIntPtr* socketDescriptor, QQuickItem* parent = 0);

    /**
     * @brief Destroys this TcpSocket
     */
    ~TcpSocket();

    /**
     * @brief Gets the current peer name
     *
     * @return Current peer name, e.g "127.0.0.1"
     */
    QString getPeer() const { return peer; }

    /**
     * @brief Sets the peer name
     *
     * @param peer The new peer name, e.g "127.0.0.1"
     */
    void setPeer(QString peer);

    /**
     * @brief Gets the current port
     *
     * @return Current port
     */
    int getPort() const { return port; }

    /**
     * @brief Sets the port
     *
     * @param port The new port, must be in [0,65535]
     */
    void setPort(int port);

    /** @endcond */

public slots:

    /**
     * @brief Initializes the socket with the given native descriptor (returned from TcpServer), calls socketDescriptor->deleteLater() in the end
     *
     * @param socketDescriptor Native socket descriptor, calls deleterLater() on it in the end
     */
    void setSocketDescriptor(QMLTcpSockets::QIntPtr* socketDescriptor);

    /**
     * Sets the given low level option to the value described by value.
     *
     * @param option The option of TcpSocketEnums::SocketOption type (see http://doc.qt.io/qt-5/qabstractsocket.html#SocketOption-enum)
     * @param value The value
     */
    void setSocketOption(int option, QVariant value);

    /**
     * @brief Initiates a connection to the peer on port
     */
    void connectToHost();

    /**
     * @brief Starts closing the socket
     */
    void disconnectFromHost();

    /**
     * @brief Writes bytes over the socket
     *
     * @param bytes Bytes to write, all must be within [0x00,0xFF]
     * @return Whether all bytes were successfully written
     */
    bool writeBytes(QList<int> bytes);

signals:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Emitted when the peer name changes
     */
    void peerChanged();

    /**
     * @brief Emitted whe the port changes
     */
    void portChanged();

    /** @endcond */

    /**
     * @brief Emitted when the socket is connected
     */
    void connected();

    /**
     * @brief Emitted when the socket is disconected
     */
    void disconnected();

    /**
     * @brief Emitted when there is an error
     *
     * @param socketError The error of TcpSocketEnums::SocketError type (see http://doc.qt.io/qt-5/qabstractsocket.html#SocketError-enum)
     */
    void error(int socketError);

    /**
     * @brief Emitted when some bytes are received
     *
     * @param bytes Byte array that was received, all elements are guaranteed to be in [0x00, 0xFF]
     */
    void bytesReceived(QList<int> bytes);

private slots:

    /**
     * @brief Publishes all available received bytes via bytesReceived(QVariant)
     */
    void publish();

    /**
     * @brief Emits error(int socketError)
     *
     * @param socketError The socket error to emit
     */
    void emitErrorAsInt(QAbstractSocket::SocketError socketError);

private:

    QTcpSocket socket;  ///< The low level socket
    QString peer;       ///< Peer address
    quint16 port;       ///< Connection port

};

}

Q_DECLARE_METATYPE(QMLTcpSockets::TcpSocket*)

#endif /* TCPSOCKET_H */
