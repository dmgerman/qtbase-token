CONFIG += testcase
CONFIG += parallel_test
TARGET = tst_qrawfont

QT = core core-private gui gui-private testlib

SOURCES += \
    tst_qrawfont.cpp

INCLUDEPATH += $$QT_SOURCE_TREE/src/3rdparty/harfbuzz/src

TESTDATA += testfont_bold_italic.ttf  testfont.ttf
