CONFIG += testcase
TARGET = tst_qprinter
QT += printsupport widgets testlib
SOURCES  += tst_qprinter.cpp

mac*:CONFIG+=insignificant_test # QTBUG-25292
