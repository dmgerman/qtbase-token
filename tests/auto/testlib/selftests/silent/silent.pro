SOURCES += tst_silent.cpp
QT = core testlib-private

mac:CONFIG -= app_bundle
CONFIG -= debug_and_release_target

TARGET = silent
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
