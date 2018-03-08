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
 * @file TcpServer.h
 * @brief QML wrapper header for QTcpServer
 * @author Ayberk Özgür
 * @date 2016-11-10
 */

#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QQuickItem>

#include "QTcpServerPub.h"
#include "TcpSocket.h"
#include "QIntPtr.h"

namespace QMLTcpSockets{

/**
 * @brief QML wrapper for QTcpServer
 */
class TcpServer : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

    /** @brief Whether to listen for incoming connections, default false */
    Q_PROPERTY(bool listen READ isListening WRITE setListening NOTIFY listeningChanged)

    /** @brief Address to listen on, default "0.0.0.0" i.e any address */
    Q_PROPERTY(QString host READ getHost WRITE setHost NOTIFY hostChanged)

    /** @brief Port to listen on, must be in [0,65535], default 0 */
    Q_PROPERTY(int port READ getPort WRITE setPort NOTIFY portChanged)

public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates a new TcpServer with the given QML parent
     *
     * @param parent The QML parent
     */
    TcpServer(QQuickItem* parent = 0);

    /**
     * @brief Destroys this TcpServer
     */
    ~TcpServer();

    /**
     * @brief Gets whether the socket is listening
     *
     * @return Whether the socket is listening
     */
    bool isListening() const;

    /**
     * @brief Enables/disables listening
     *
     * @param enable Whether to listen or close the socket and stop listening
     */
    void setListening(bool enable);

    /**
     * @brief Gets the current host name
     *
     * @return Current host name, e.g "127.0.0.1"
     */
    QString getHost() const { return host; }

    /**
     * @brief Sets the host name
     *
     * @param host The new host name, e.g "127.0.0.1"
     */
    void setHost(QString host);

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

signals:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Emitted when listening changes
     */
    void listeningChanged();

    /**
     * @brief Emitted when the host name changes
     */
    void hostChanged();

    /**
     * @brief Emitted whe the port changes
     */
    void portChanged();

    /** @endcond */

    /**
     * @brief Emitted when a new connection is made to the server, socketDescriptor must be passed to a TcpSocket or a TcpSocketFactory to create the socket
     *
     * @param socketDescriptor Native descriptor to the socket that has just connected
     */
    void newConnection(QMLTcpSockets::QIntPtr* socketDescriptor);

private slots:

    /**
     * @brief Gets the incoming connection descriptor, wraps it in a QIntPtr and publishes it
     */
    void publishIncomingConnection(qintptr socketDescriptor);

private:

    QString host;           ///< Host address, e.g "127.0.0.1"
    quint16 port;           ///< Port to listen to
    QTcpServerPub server;   ///< The QTcpServer object to wrap

};

}

#endif /* TCPSERVER_H */
