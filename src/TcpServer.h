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

class TcpServer : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

public:

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

};

#endif /* TCPSERVER_H */
