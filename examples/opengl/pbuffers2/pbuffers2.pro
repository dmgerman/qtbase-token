######################################################################
# Automatically generated by qmake (2.01a) Fri May 12 17:15:46 2006
######################################################################

TEMPLATE = app
TARGET =
DEPENDPATH += .
INCLUDEPATH += .

QT += opengl svg

# Input
HEADERS += glwidget.h
SOURCES += glwidget.cpp main.cpp
RESOURCES += pbuffers2.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/opengl/pbuffers2
sources.files = $$SOURCES $$HEADERS $$RESOURCES pbuffers2.pro *.png *.svg
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/opengl/pbuffers2
INSTALLS += target sources

symbian: CONFIG += qt_example
