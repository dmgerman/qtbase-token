CONFIG += testcase
TARGET = tst_qmdisubwindow
QT += widgets testlib
INCLUDEPATH += .
SOURCES  += tst_qmdisubwindow.cpp
DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII


mac*:CONFIG+=insignificant_test # QTBUG-25297
