# Qt network kernel module

PRECOMPILED_HEADER = ../corelib/global/qt_pch.h
INCLUDEPATH += $$PWD

HEADERS += kernel/qauthenticator.h \
	   kernel/qauthenticator_p.h \
           kernel/qdnslookup.h \
           kernel/qdnslookup_p.h \
           kernel/qhostaddress.h \
           kernel/qhostaddress_p.h \
           kernel/qhostinfo.h \
           kernel/qhostinfo_p.h \
           kernel/qurlinfo.h \
           kernel/qnetworkproxy.h \
           kernel/qnetworkproxy_p.h \
	   kernel/qnetworkinterface.h \
	   kernel/qnetworkinterface_p.h

SOURCES += kernel/qauthenticator.cpp \
           kernel/qdnslookup.cpp \
           kernel/qhostaddress.cpp \
           kernel/qhostinfo.cpp \
           kernel/qurlinfo.cpp \
           kernel/qnetworkproxy.cpp \
	   kernel/qnetworkinterface.cpp

unix:SOURCES += kernel/qdnslookup_unix.cpp kernel/qhostinfo_unix.cpp kernel/qnetworkinterface_unix.cpp
win32: {
    HEADERS += kernel/qnetworkinterface_win_p.h
    SOURCES += kernel/qdnslookup_win.cpp kernel/qhostinfo_win.cpp kernel/qnetworkinterface_win.cpp
}
integrity:SOURCES += kernel/qdnslookup_unix.cpp kernel/qhostinfo_unix.cpp kernel/qnetworkinterface_unix.cpp

mac:LIBS_PRIVATE += -framework SystemConfiguration -framework CoreFoundation
mac:SOURCES += kernel/qnetworkproxy_mac.cpp
else:win32:SOURCES += kernel/qnetworkproxy_win.cpp
else:SOURCES += kernel/qnetworkproxy_generic.cpp
