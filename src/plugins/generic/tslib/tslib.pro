TARGET = qtslibplugin
load(qt_plugin)

DESTDIR = $$QT.gui.plugins/generic
target.path = $$[QT_INSTALL_PLUGINS]/generic
INSTALLS += target

HEADERS	= qtslib.h

SOURCES	= main.cpp \
	qtslib.cpp

LIBS += -lts

OTHER_FILES += tslib.json
