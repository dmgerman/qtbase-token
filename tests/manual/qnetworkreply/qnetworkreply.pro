CONFIG += testcase
TEMPLATE = app
TARGET = tst_qnetworkreply

QT -= gui
QT += network testlib

SOURCES += main.cpp
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
