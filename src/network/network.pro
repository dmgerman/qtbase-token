load(qt_module)

# Qt network module
TARGET   = QtNetwork
QPRO_PWD = $$PWD

CONFIG += module
MODULE_PRI = ../modules/qt_network.pri

DEFINES += QT_BUILD_NETWORK_LIB QT_NO_USING_NAMESPACE
#DEFINES += QLOCALSERVER_DEBUG QLOCALSOCKET_DEBUG
#DEFINES += QNETWORKDISKCACHE_DEBUG
#DEFINES += QSSLSOCKET_DEBUG
#DEFINES += QHOSTINFO_DEBUG
#DEFINES += QABSTRACTSOCKET_DEBUG QNATIVESOCKETENGINE_DEBUG
#DEFINES += QTCPSOCKETENGINE_DEBUG QTCPSOCKET_DEBUG QTCPSERVER_DEBUG QSSLSOCKET_DEBUG
#DEFINES += QUDPSOCKET_DEBUG QUDPSERVER_DEBUG
QT = core-private
win32-msvc*|win32-icc:QMAKE_LFLAGS += /BASE:0x64000000

unix|win32-g++*:QMAKE_PKGCONFIG_REQUIRES = QtCore

load(qt_module_config)

HEADERS += $$QT_SOURCE_TREE/src/network/qtnetworkversion.h

include(access/access.pri)
include(bearer/bearer.pri)
include(doc/doc.pri)
include(kernel/kernel.pri)
include(socket/socket.pri)
include(ssl/ssl.pri)

QMAKE_LIBS += $$QMAKE_LIBS_NETWORK
