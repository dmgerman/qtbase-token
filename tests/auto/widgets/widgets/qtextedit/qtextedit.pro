CONFIG += testcase
TARGET = tst_qtextedit

QT += widgets widgets-private gui-private core-private testlib
INCLUDEPATH += ../

HEADERS +=  
SOURCES += tst_qtextedit.cpp 

wince* {
    addImages.files = fullWidthSelection/*
    addImages.path = fullWidthSelection
    DEPLOYMENT += addImages
    DEFINES += SRCDIR=\\\"./\\\"
} else {
    DEFINES += SRCDIR=\\\"$$PWD/\\\"
}

contains(QT_CONFIG,xcb):CONFIG+=insignificant_test  # QTBUG-20756 crashes on xcb
