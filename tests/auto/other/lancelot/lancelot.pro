CONFIG += testcase
CONFIG += parallel_test
TARGET = tst_lancelot
QT += xml widgets testlib
contains(QT_CONFIG, opengl)|contains(QT_CONFIG, opengles1)|contains(QT_CONFIG, opengles2):QT += opengl

SOURCES += tst_lancelot.cpp \
           paintcommands.cpp
HEADERS += paintcommands.h
RESOURCES += images.qrc

include($$PWD/../../../baselineserver/shared/qbaselinetest.pri)

TESTDATA += scripts/*
