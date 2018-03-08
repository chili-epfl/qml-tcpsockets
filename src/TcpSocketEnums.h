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
 * @file TcpSocketEnums.h
 * @brief Wrapper to expose QAbstractSocket enums
 * @author Ayberk Özgür
 * @date 2016-11-16
 */

#ifndef TCPSOCKETENUMS_H
#define TCPSOCKETENUMS_H

#include <QAbstractSocket>

namespace QMLTcpSockets{

/**
 * @brief Wrapper to expose QAbstractSocket enums, see http://doc.qt.io/qt-5/qabstractsocket.html
 */
class TcpSocketEnums : public QAbstractSocket {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates a new TcpSocketEnums with the given Qt parent
     *
     * @param parent The Qt parent
     */
    TcpSocketEnums(QObject* parent = 0);

    /**
     * @brief Destroys this TcpSocketEnums
     */
    ~TcpSocketEnums();

    /** @endcod */

};

}

#endif /* TCPSOCKETENUMS_H */
