# Qt dialogs module

HEADERS += \
        dialogs/qabstractprintdialog.h \
        dialogs/qabstractprintdialog_p.h \
        dialogs/qabstractpagesetupdialog.h \
        dialogs/qabstractpagesetupdialog_p.h \
        dialogs/qpagesetupdialog.h \
        dialogs/qprintdialog.h \
        dialogs/qprintpreviewdialog.h

mac {
    OBJECTIVE_SOURCES += dialogs/qpagesetupdialog_mac.mm \
                         dialogs/qprintdialog_mac.mm
    LIBS += -framework Cocoa
}

win32 {
    SOURCES += dialogs/qpagesetupdialog_win.cpp \
               dialogs/qprintdialog_win.cpp
}

unix:!mac {
    HEADERS += dialogs/qpagesetupdialog_unix_p.h
    SOURCES += dialogs/qprintdialog_unix.cpp \
               dialogs/qpagesetupdialog_unix.cpp
    FORMS += dialogs/qprintsettingsoutput.ui \
    dialogs/qprintwidget.ui \
    dialogs/qprintpropertieswidget.ui
}

INCLUDEPATH += $$PWD

SOURCES += \
        dialogs/qabstractprintdialog.cpp \
        dialogs/qabstractpagesetupdialog.cpp \
        dialogs/qpagesetupdialog.cpp \
        dialogs/qprintpreviewdialog.cpp

FORMS += dialogs/qpagesetupwidget.ui
RESOURCES += dialogs/qprintdialog.qrc
