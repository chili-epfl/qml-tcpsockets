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
 * @file QMLTcpSocketsPlugin.h
 * @brief Object that exposes the QMLTcpSockets plugin components as QML objects
 * @author Ayberk Özgür
 * @date 2016-11-10
 */

#include "QMLTcpSocketsPlugin.h"

#include "TcpServer.h"
#include "TcpSocket.h"
#include "QIntPtr.h"
#include "TcpSocketFactory.h"
#include "TcpSocketEnums.h"

namespace QMLTcpSockets{

void QMLTcpSocketsPlugin::registerTypes(const char* uri){
    qmlRegisterType<TcpServer>(uri, 1, 0, "TcpServer");
    qmlRegisterType<TcpSocket>(uri, 1, 0, "TcpSocket");
    qmlRegisterType<QIntPtr>(uri, 1, 0, "QIntPtr");
    qmlRegisterSingletonType<TcpSocketFactory>(uri, 1, 0, "TcpSocketFactory",
                                               [] (QQmlEngine* qmlEngine, QJSEngine* jsEngine)->QObject* {
                                                   Q_UNUSED(qmlEngine)
                                                   Q_UNUSED(jsEngine)
                                                   return new TcpSocketFactory();
                                               });
    qmlRegisterType<TcpSocketEnums>(uri, 1, 0, "TcpSocketEnums");
}

}
