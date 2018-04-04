qml-tcpsockets-sample
=====================

Example use of qml-tcpsockets in a bidirectional server-client communication scenario. Follow the build instructions in
[the qml-tcpsockets README](../../README.md) before trying to run this sample. It is tested with Qt 5.10.1 on the
following:

- Ubuntu 17.10
- macOS 10.13.3 with Xcode 9.3
- Windows 10 (UWP x64 (MSVC 2017)) with Visual Studio 2017 Community (with `Universal Windows Platform development` and `C++ Universal Windows Platform tools`)
- Android 7.1.2 with Ubuntu 17.10 host with Android API 23, Android SDK Tools 25.2.5 and Android NDK r10e

**Note:** On Windows, will not be able to listen on nor connect to localhost sockets due to the sandboxing of WinRT apps. You must connect to a copy of the same demo running on another device.

build & run [Ubuntu & macOS & Android]
--------------------------------------

Load the project into QtCreator and press the Run button with the big green arrow.

build & run [Windows]
---------------------

  - Load the project into QtCreator, select the `Release` build (and not the `Debug` and `Profile` build)
  - Press the Run button with the big green arrow once, this will install and launch the app (you may have to enable `Developer mode` in `Settings` -> `Update & Security` -> `For developers` -> `Use developer features`; this windows will pop up anyway if you haven't enabled it already)
  - For all subsequent launches, use `qml-cache-demo` now installed in the Start Menu
