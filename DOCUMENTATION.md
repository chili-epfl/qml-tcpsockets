# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`QMLTcpSockets`](#namespaceQMLTcpSockets) | 

# namespace `QMLTcpSockets` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`QMLTcpSockets::QIntPtr`](#classQMLTcpSockets_1_1QIntPtr) | QObject wrapper for qintptr. Can be passed around in QML but doesn't have any API.
`class `[`QMLTcpSockets::TcpServer`](#classQMLTcpSockets_1_1TcpServer) | QML wrapper for QTcpServer.
`class `[`QMLTcpSockets::TcpSocket`](#classQMLTcpSockets_1_1TcpSocket) | QML wrapper for QTcpSocket.
`class `[`QMLTcpSockets::TcpSocketFactory`](#classQMLTcpSockets_1_1TcpSocketFactory) | Creates new [TcpSocket](#classQMLTcpSockets_1_1TcpSocket) from native socket descriptor (returned from a [TcpServer](#classQMLTcpSockets_1_1TcpServer) incoming connection).

# class `QMLTcpSockets::QIntPtr` 

```
class QMLTcpSockets::QIntPtr
  : public QObject
```  

QObject wrapper for qintptr. Can be passed around in QML but doesn't have any API.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `QMLTcpSockets::TcpServer` 

```
class QMLTcpSockets::TcpServer
  : public QQuickItem
```  

QML wrapper for QTcpServer.

Due to the sandboxing of WinRT, cannot listen on nor connect to localhost sockets on this platform.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} bool `[`listen`](#classQMLTcpSockets_1_1TcpServer_1a5ac42352045298060cad40538fcc7fcc) | Whether to listen for incoming connections, default false.
`{property} QString `[`host`](#classQMLTcpSockets_1_1TcpServer_1a914ff509ac395f395170c14784dfe98c) | Address to listen on, default "0.0.0.0" i.e any address.
`{property} int `[`port`](#classQMLTcpSockets_1_1TcpServer_1a8136392490a77db01b9b555fd6ac0327) | Port to listen on, must be in [0,65535], default 0.
`{signal} public void `[`newConnection`](#classQMLTcpSockets_1_1TcpServer_1ac45ce6a439ed6850926c1ef118f7b9e2)`(`[`QMLTcpSockets::QIntPtr`](#classQMLTcpSockets_1_1QIntPtr)` * socketDescriptor)` | Emitted when a new connection is made to the server, socketDescriptor must be passed to a [TcpSocket](#classQMLTcpSockets_1_1TcpSocket) or a [TcpSocketFactory](#classQMLTcpSockets_1_1TcpSocketFactory) to create the socket.

## Members

#### `{property} bool `[`listen`](#classQMLTcpSockets_1_1TcpServer_1a5ac42352045298060cad40538fcc7fcc) 

Whether to listen for incoming connections, default false.

#### `{property} QString `[`host`](#classQMLTcpSockets_1_1TcpServer_1a914ff509ac395f395170c14784dfe98c) 

Address to listen on, default "0.0.0.0" i.e any address.

Host address, e.g "127.0.0.1".

#### `{property} int `[`port`](#classQMLTcpSockets_1_1TcpServer_1a8136392490a77db01b9b555fd6ac0327) 

Port to listen on, must be in [0,65535], default 0.

#### `{signal} public void `[`newConnection`](#classQMLTcpSockets_1_1TcpServer_1ac45ce6a439ed6850926c1ef118f7b9e2)`(`[`QMLTcpSockets::QIntPtr`](#classQMLTcpSockets_1_1QIntPtr)` * socketDescriptor)` 

Emitted when a new connection is made to the server, socketDescriptor must be passed to a [TcpSocket](#classQMLTcpSockets_1_1TcpSocket) or a [TcpSocketFactory](#classQMLTcpSockets_1_1TcpSocketFactory) to create the socket.

#### Parameters
* `socketDescriptor` Native descriptor to the socket that has just connected

# class `QMLTcpSockets::TcpSocket` 

```
class QMLTcpSockets::TcpSocket
  : public QQuickItem
```  

QML wrapper for QTcpSocket.

Can be created from a native socket descriptor returned from a [TcpServer](#classQMLTcpSockets_1_1TcpServer) incoming connection, or can connect to a peer on its own. Due to the sandboxing of WinRT, cannot listen on nor connect to localhost sockets on this platform.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} QString `[`peer`](#classQMLTcpSockets_1_1TcpSocket_1a22591ae1e0e126afd1c9b2aa1752a751) | Address to connect to, or address of the already open remote connection, default "".
`{property} int `[`port`](#classQMLTcpSockets_1_1TcpSocket_1a66c76937c0f7c0c416b98477d950e92b) | Port to connect to, or port of the already open remote connection , must be in [0,65535], default 0.
`{signal} public void `[`connected`](#classQMLTcpSockets_1_1TcpSocket_1aeddb4f6b24510128eceb097ea7b147b4)`()` | Emitted when the socket is connected.
`{signal} public void `[`disconnected`](#classQMLTcpSockets_1_1TcpSocket_1ac8a294ab7d4b9b2a8268f8dc0ce3b7bd)`()` | Emitted when the socket is disconected.
`{signal} public void `[`error`](#classQMLTcpSockets_1_1TcpSocket_1a43ef22856c779ebc659dd97ab485b40c)`(int socketError)` | Emitted when there is an error.
`{signal} public void `[`bytesReceived`](#classQMLTcpSockets_1_1TcpSocket_1a73bed2b09c433069bfab35a7106c1f04)`(QList< int > bytes)` | Emitted when some bytes are received.
`{slot} public void `[`setSocketDescriptor`](#classQMLTcpSockets_1_1TcpSocket_1af250516ca302a2eeb2a5a75b07471337)`(`[`QMLTcpSockets::QIntPtr`](#classQMLTcpSockets_1_1QIntPtr)` * socketDescriptor)` | Initializes the socket with the given native descriptor (returned from [TcpServer](#classQMLTcpSockets_1_1TcpServer)), calls socketDescriptor->deleteLater() in the end.
`{slot} public void `[`setSocketOption`](#classQMLTcpSockets_1_1TcpSocket_1a8e4e9159b63d0a960f6928ee335bdcd6)`(int option,QVariant value)` | Sets the given low level option to the value described by value.
`{slot} public void `[`connectToHost`](#classQMLTcpSockets_1_1TcpSocket_1a515f7ef9263e1d0a734420020c58d23f)`()` | Initiates a connection to the peer on port.
`{slot} public void `[`disconnectFromHost`](#classQMLTcpSockets_1_1TcpSocket_1a1c5faa0f97dfb4ed6b880ddef3510a9c)`()` | Starts closing the socket.
`{slot} public bool `[`writeBytes`](#classQMLTcpSockets_1_1TcpSocket_1a8d4be4bbddd1fb2f527277e5cacd5d33)`(QList< int > bytes)` | Writes bytes over the socket.

## Members

#### `{property} QString `[`peer`](#classQMLTcpSockets_1_1TcpSocket_1a22591ae1e0e126afd1c9b2aa1752a751) 

Address to connect to, or address of the already open remote connection, default "".

Peer address.

#### `{property} int `[`port`](#classQMLTcpSockets_1_1TcpSocket_1a66c76937c0f7c0c416b98477d950e92b) 

Port to connect to, or port of the already open remote connection , must be in [0,65535], default 0.

#### `{signal} public void `[`connected`](#classQMLTcpSockets_1_1TcpSocket_1aeddb4f6b24510128eceb097ea7b147b4)`()` 

Emitted when the socket is connected.

#### `{signal} public void `[`disconnected`](#classQMLTcpSockets_1_1TcpSocket_1ac8a294ab7d4b9b2a8268f8dc0ce3b7bd)`()` 

Emitted when the socket is disconected.

#### `{signal} public void `[`error`](#classQMLTcpSockets_1_1TcpSocket_1a43ef22856c779ebc659dd97ab485b40c)`(int socketError)` 

Emitted when there is an error.

#### Parameters
* `socketError` The error of TcpSocketEnums::SocketError type (see [http://doc.qt.io/qt-5/qabstractsocket.html#SocketError-enum](http://doc.qt.io/qt-5/qabstractsocket.html#SocketError-enum))

#### `{signal} public void `[`bytesReceived`](#classQMLTcpSockets_1_1TcpSocket_1a73bed2b09c433069bfab35a7106c1f04)`(QList< int > bytes)` 

Emitted when some bytes are received.

#### Parameters
* `bytes` Byte array that was received, all elements are guaranteed to be in [0x00, 0xFF]

#### `{slot} public void `[`setSocketDescriptor`](#classQMLTcpSockets_1_1TcpSocket_1af250516ca302a2eeb2a5a75b07471337)`(`[`QMLTcpSockets::QIntPtr`](#classQMLTcpSockets_1_1QIntPtr)` * socketDescriptor)` 

Initializes the socket with the given native descriptor (returned from [TcpServer](#classQMLTcpSockets_1_1TcpServer)), calls socketDescriptor->deleteLater() in the end.

#### Parameters
* `socketDescriptor` Native socket descriptor, calls deleterLater() on it in the end

#### `{slot} public void `[`setSocketOption`](#classQMLTcpSockets_1_1TcpSocket_1a8e4e9159b63d0a960f6928ee335bdcd6)`(int option,QVariant value)` 

Sets the given low level option to the value described by value.

#### Parameters
* `option` The option of TcpSocketEnums::SocketOption type (see [http://doc.qt.io/qt-5/qabstractsocket.html#SocketOption-enum](http://doc.qt.io/qt-5/qabstractsocket.html#SocketOption-enum)) 

* `value` The value

#### `{slot} public void `[`connectToHost`](#classQMLTcpSockets_1_1TcpSocket_1a515f7ef9263e1d0a734420020c58d23f)`()` 

Initiates a connection to the peer on port.

#### `{slot} public void `[`disconnectFromHost`](#classQMLTcpSockets_1_1TcpSocket_1a1c5faa0f97dfb4ed6b880ddef3510a9c)`()` 

Starts closing the socket.

#### `{slot} public bool `[`writeBytes`](#classQMLTcpSockets_1_1TcpSocket_1a8d4be4bbddd1fb2f527277e5cacd5d33)`(QList< int > bytes)` 

Writes bytes over the socket.

#### Parameters
* `bytes` Bytes to write, all must be within [0x00,0xFF] 

#### Returns
Whether all bytes were successfully written

# class `QMLTcpSockets::TcpSocketFactory` 

```
class QMLTcpSockets::TcpSocketFactory
  : public QQuickItem
```  

Creates new [TcpSocket](#classQMLTcpSockets_1_1TcpSocket) from native socket descriptor (returned from a [TcpServer](#classQMLTcpSockets_1_1TcpServer) incoming connection).

This class is **singleton**, you can call `ThisClass.anyFunction()` and use `ThisClass.anyProperty` directly.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{slot} public static `[`QMLTcpSockets::TcpSocket`](#classQMLTcpSockets_1_1TcpSocket)` * `[`fromDescriptor`](#classQMLTcpSockets_1_1TcpSocketFactory_1a53394243db157558b3fbe26748a12642)`(`[`QMLTcpSockets::QIntPtr`](#classQMLTcpSockets_1_1QIntPtr)` * socketDescriptor,QQuickItem * parent)` | Creates and returns a new open socket that wraps the native socket descriptor, with the given QML parent (optional)

## Members

#### `{slot} public static `[`QMLTcpSockets::TcpSocket`](#classQMLTcpSockets_1_1TcpSocket)` * `[`fromDescriptor`](#classQMLTcpSockets_1_1TcpSocketFactory_1a53394243db157558b3fbe26748a12642)`(`[`QMLTcpSockets::QIntPtr`](#classQMLTcpSockets_1_1QIntPtr)` * socketDescriptor,QQuickItem * parent)` 

Creates and returns a new open socket that wraps the native socket descriptor, with the given QML parent (optional)

#### Parameters
* `socketDescriptor` Native socket descriptor 

* `parent` QML parent of the newly created [TcpSocket](#classQMLTcpSockets_1_1TcpSocket)

#### Returns
New socket, open if the descriptor is valid

Generated by [Moxygen](https://sourcey.com/moxygen)