CONFIG += testcase
TARGET = tst_qitemdelegate
QT += widgets testlib
SOURCES         += tst_qitemdelegate.cpp

win32:!wince*: LIBS += -lUser32

linux-*:system(". /etc/lsb-release && [ $DISTRIB_CODENAME = oneiric ]"):CONFIG+=insignificant_test # QTBUG-23637
