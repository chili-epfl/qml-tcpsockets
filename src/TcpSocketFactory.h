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
 * @file TcpSocketFactory.h
 * @brief Singleton TcpSocket factory for QML
 * @author Ayberk Özgür
 * @date 2016-11-15
 */

#ifndef TCPSOCKETFACTORY_H
#define TCPSOCKETFACTORY_H

#include <QQuickItem>

#include "TcpSocket.h"
#include "QIntPtr.h"

namespace QMLTcpSockets{

/**
 * @brief Creates new TcpSocket from native socket descriptor (returned from a TcpServer incoming connection).
 * @singleton
 */
class TcpSocketFactory : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates a new TcpSocketFactory with the given QML parent
     *
     * @param parent The QML parent
     */
    TcpSocketFactory(QQuickItem* parent = 0);

    /**
     * @brief Destroys this TcpSocketFactory
     */
    ~TcpSocketFactory();

    /** @endcond */

public slots:

    /**
     * @brief Creates and returns a new open socket that wraps the native socket descriptor, with the given QML parent (optional)
     *
     * @param socketDescriptor Native socket descriptor
     * @param parent QML parent of the newly created TcpSocket
     * @return New socket, open if the descriptor is valid
     */
    static TcpSocket* fromDescriptor(QIntPtr* socketDescriptor, QQuickItem* parent = 0);

};

}

#endif /* TCPSOCKETFACTORY_H */
