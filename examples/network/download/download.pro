######################################################################
# Automatically generated by qmake (2.01a) fr. nov. 16 13:18:20 2007
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
QT = core network
CONFIG += console

# Input
SOURCES += main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/network/download
sources.files = $$SOURCES $$HEADERS $$FORMS $$RESOURCES *.pro *.png
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/network/download
INSTALLS += target sources

symbian: CONFIG += qt_example
