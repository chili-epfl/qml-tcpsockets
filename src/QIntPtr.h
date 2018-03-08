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
 * @file QIntPtr.h
 * @brief QObject wrapper for qintptr
 * @author Ayberk Özgür
 * @date 2016-11-15
 */

#ifndef QINTPTR_H
#define QINTPTR_H

#include <QObject>

namespace QMLTcpSockets{

/**
 * @brief QObject wrapper for qintptr. Can be passed around in QML but doesn't have any API.
 */
class QIntPtr : public QObject {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates a new QIntPtr with the given Qt parent
     *
     * @param parent The Qt parent
     */
    QIntPtr(QObject* parent = 0);

    /**
     * @brief Destroys this QIntPtr
     */
    ~QIntPtr();

    qintptr ptr; ///< Wrapped low level pointer

    /** @endcond */

};

}

Q_DECLARE_METATYPE(QMLTcpSockets::QIntPtr*)

#endif /* QINTPTR_H */
