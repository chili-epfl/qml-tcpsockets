qml-tcpsockets
==============

qml-tcpsockets contains QML wrappers for QTcpServer and QTcpSocket. More Qt Networking wrappers might come soon. It is
tested with Qt 5.10.0 on the following:

  - Ubuntu 17.10
  - macOS 10.13.3
  - ~~Android 6.0.1 (arm-v7) built with SDK API 19 and NDK r10e on Ubuntu 16.04 host~~ Not yet

See [samples/](samples/) for example uses.

See [DOCUMENTATION.md](DOCUMENTATION.md) for the API.

build
-----

Regardless of the platform, using the appropriate `qmake` (found under `qt-install-dir/qt-version/target-platform/bin/qmake`):

```
    $ mkdir build && cd build
    $ qmake ..
    $ make install
```

This will install the QML plugin inside the Qt sysroot. **Be aware that this is not a sandboxed installation.**

build documentation
-------------------

Install dependencies:
```
    $ apt install doxygen doxyqml
    $ git clone git@github.com:sourcey/moxygen.git && cd moxygen && npm install -g .
```

Then, generate the documentation:
```
    $ doxygen
    $ moxygen --output DOCUMENTATION.md xml
```
