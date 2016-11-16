import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

import QMLTcpSockets 1.0

ApplicationWindow {
    id: window
    visible: true
    minimumHeight: height
    minimumWidth: width

    function getIntArr(str){
        var ret = [];
        for(var i=0;i<str.length;i++)
            ret.push(str.charCodeAt(i));
        return ret;
    }

    function getStr(intArr){
        var str = "";
        for(var i=0;i<intArr.length;i++)
            str += String.fromCharCode(intArr[i]);
        return str;
    }

    TcpServer{
        id: server

        port: parseInt(serverPortField.text)

        onNewConnection: {
            serverSocket = TcpSocketFactory.fromDescriptor(socketDescriptor);
            serverSocket.setSocketOption(TcpSocketEnums.LowDelayOption, 1);
            serverSocket.bytesReceived.connect(function(bytes){console.log("Server received: " + getStr(bytes)); });
            serverSocket.connected.connect(function(){console.log("Server socket connected."); });
            serverSocket.disconnected.connect(function(){console.log("Server socket disconnected."); });
            serverSocket.peerChanged.connect(function(){console.log("Server socket peer changed: " + serverSocket.peer); });
            serverSocket.portChanged.connect(function(){console.log("Server socket port changed: " + serverSocket.port); });
        }
    }

    property var serverSocket: null

    TcpSocket{
        id: clientSocket

        peer: clientAddressField.text
        port: parseInt(clientPortField.text)
        onBytesReceived: console.log("Client received: " + getStr(bytes))
        onConnected: {
            console.log("Client socket connected");
            setSocketOption(TcpSocketEnums.LowDelayOption, 1);
        }
        onDisconnected: console.log("Client socket disconnected")
        onPeerChanged: console.log("Client socket peer changed: " + peer)
        onPortChanged: console.log("Client socket port changed: " + port)
    }

    Row{
        GroupBox{
            title: "Server"

            Column{
                Button{
                    text: "Listen"
                    onClicked: {
                        server.listen = true;
                        console.log("Server stared listening.");
                    }
                }

                TextField{
                    id: serverPortField
                    placeholderText: "Port to listen on"
                    inputMethodHints: Qt.ImhDigitsOnly
                    text: "1234"
                }

                Button{
                    text: "Send from server"
                    onClicked: serverSocket.writeBytes(getIntArr("hello from server !!!"))
                }
            }
        }

        GroupBox{
            title: "Client"

            Column{
                TextField{
                    id: clientAddressField
                    placeholderText: "Address to connect to"
                    text: "localhost"
                }

                TextField{
                    id: clientPortField
                    placeholderText: "Port to connect to"
                    inputMethodHints: Qt.ImhDigitsOnly
                    text: "1234"
                }

                Button{
                    text: "Connect"
                    onClicked: clientSocket.connectToHost()
                }

                Button{
                    text: "Disconnect"
                    onClicked: clientSocket.disconnectFromHost()
                }

                Button{
                    text: "Send from client"
                    onClicked: clientSocket.writeBytes(getIntArr("hello from client !!!"))
                }
            }
        }
    }
}
