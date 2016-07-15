CONFIG += testcase
TARGET = tst_qabstractitemmodel
QT += testlib

mtdir = ../../../other/modeltest
INCLUDEPATH += $$PWD/$${mtdir}
SOURCES = tst_qabstractitemmodel.cpp $${mtdir}/dynamictreemodel.cpp $${mtdir}/modeltest.cpp
HEADERS = $${mtdir}/dynamictreemodel.h $${mtdir}/modeltest.h

mac:CONFIG+=insignificant_test # QTBUG-22748
