qml-tcpsockets
==============

qml-tcpsockets contains QML wrappers for QTcpServer and QTcpSocket. More Qt Networking wrappers might come soon. It is
tested with Qt 5.6.2 on the following:

  - Ubuntu 16.04
  - Android 6.0.1 (arm-v7) built with SDK API 19 and NDK r10e on Ubuntu 16.04 host

build
-----

```
    $ mkdir build && cd build
    $ qmake ..
    $ make install
```

This will install the QML plugin inside the Qt sysroot. **Be aware that this is not a sandboxed installation.**

See [samples/](samples/) for example use of the API.

QML API
-------

### `TcpServer`

QML wrapper for QTcpServer; listens for incoming connections. When a new connection is made, emits the native socket
descriptor instead of a fully created socket, since the new TcpSocket must be created in the thread that uses it.

**Properties:**

>  - **listen** :   `bool` -    Whether to listen for incoming connections, default false
>  - **host** :     `string` -  Address to listen on, default "0.0.0.0" i.e any address
>  - **port** :     `int` -     Port to listen on, must be in [0,65535], default 0

**Signals:**

>  - **newConnection(QIntPtr socketDescriptor)**: Emitted when a new connection is made to the server, socketDescriptor must be passed to a TcpSocket or a TcpSocketFactory to create the socket

### `TcpSocket`

QML wrapper for QTcpSocket; can be created from a native socket descriptor returned from a TcpServer incoming
connection, or can connect to a peer on its own.

**Properties:**

>  - **peer** :     `string` -  Address to connect to, or address of the already open remote connection, default ""
>  - **port** :     `int` -     Port to connect to, or port of the already open remote connection , must be in [0,65535], default 0

**Signals:**

>  - **connected()** :                      Emitted when the socket connects
>  - **disconnected()** :                   Emitted when the socket disconnects
>  - **error(enum socketError)** :          Emitted when an error occurs
>  - **bytesReceived(list<int> bytes)** :   Emitted when new bytes arrive, all elements will be within [0x00, 0xFF]

**Slots:**

>  - **void setSocketDescriptor(QIntPtr socketDescriptor)**: Wraps the native socket descriptor of the already open socket (coming from TcpServer) with this TcpSocket, the socket will be ready to use
>  - **void connectToHost()**:                               Connects to the given peer on the given port
>  - **void disconnectFromHost()**:                          Disconnects from the host
>  - **bool writeBytes(list<int> bytes)**:                   Writes the bytes to the socket, each element must be within [0x00, 0xFF], returns whether all bytes were successfully written

### `TcpSocketFactory`

Singleton object to create new a TcpSocket from a native socket descriptor (returned from a TcpServer incoming
connection).

**Properties:**

>  - **TcpSocket fromDescriptor(QIntPtr socketDescriptor, Item parent)**: Creates and returns a new open socket that wraps the native socket descriptor, with the given QML parent (optional)

### `QIntPtr`

Object that wraps qintptr. Can be passed around in QML but doesn't have any API.
