qml-tcpsockets
==============

qml-tcpsockets contains QML wrappers for QTcpServer and QTcpSocket. More Qt Networking wrappers might come soon. It is
tested with Qt 5.6.2 on the following:

  - Ubuntu 16.04
  - Android 6.0.1 (arm-v7) built with SDK API 19 and NDK r10e on Ubuntu 16.04 host

See [samples/](samples/) for example uses.

See [DOCUMENTATION.md](DOCUMENTATION.md) for the API.

build
-----

```
    $ mkdir build && cd build
    $ qmake ..
    $ make install
```

This will install the QML plugin inside the Qt sysroot. **Be aware that this is not a sandboxed installation.**

build documentation
-------------------

```
    $ doxygen
    $ moxygen --output DOCUMENTATION.md xml
```
