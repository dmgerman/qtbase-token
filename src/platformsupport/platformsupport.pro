load(qt_module)
TARGET     = QtPlatformSupport
QPRO_PWD   = $$PWD
QT         += core-private gui-private
TEMPLATE   = lib
DESTDIR    = $$QT.gui.libs

CONFIG += staticlib
mac:LIBS += -lz -framework CoreFoundation -framework Carbon

MODULE_PRI = ../modules/qt_platformsupport.pri

DEFINES += QT_BUILD_PLATFORMSUPPORT_LIB

load(qt_module_config)

unix|win32-g++*:QMAKE_PKGCONFIG_REQUIRES = QtCore QtGui

HEADERS += $$PWD/qtplatformsupportversion.h

DEFINES += QT_NO_CAST_FROM_ASCII
PRECOMPILED_HEADER = ../corelib/global/qt_pch.h

include(cglconvenience/cglconvenience.pri)
include(dnd/dnd.pri)
include(eglconvenience/eglconvenience.pri)
include(eventdispatchers/eventdispatchers.pri)
include(fb_base/fb_base.pri)
include(fontdatabases/fontdatabases.pri)
include(glxconvenience/glxconvenience.pri)
include(input/input.pri)
include(inputcontext/inputcontext.pri)
include(devicediscovery/devicediscovery.pri)
include(services/services.pri)
include(themes/themes.pri)
