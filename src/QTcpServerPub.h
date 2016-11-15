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
 * @file QTcpServerPub.h
 * @brief A QTcpServer that emits incomingConnection() as signal (duh)
 * @author Ayberk Özgür
 * @date 2016-11-15
 */

#ifndef QTCPSERVERPUB_H
#define QTCPSERVERPUB_H

#include <QTcpServer>

class QTcpServerPub : public QTcpServer {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

public:

    /**
     * @brief Creates a new QTcpServerPub with the given Qt parent
     *
     * @param parent The Qt parent
     */
    QTcpServerPub(QObject* parent = 0);

signals:

    /**
     * @brief Emitted when there's a new incoming connection
     *
     * @param socketDescriptor Descriptor of the incoming connection that can be used to create a QTcpSocket
     */
    void incomingConnectionSignal(qintptr socketDescriptor);

protected:

    /**
     * @brief Called by the super class when there's a new incoming connection
     *
     * @param socketDescriptor Descriptor of the incoming connection that can be used to create a QTcpSocket
     */
    void incomingConnection(qintptr socketDescriptor) override;

};

#endif /* QTCPSERVERPUB_H */
