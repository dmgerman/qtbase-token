CONFIG += testcase
SOURCES  += ../tst_qclipboard.cpp
TARGET = ../tst_qclipboard
QT += testlib

win32 {
  CONFIG(debug, debug|release) {
    TARGET = ../../debug/tst_qclipboard
} else {
    TARGET = ../../release/tst_qclipboard
  }
}

wince* {
  DEPLOYMENT += rsc reg_resource
}

load(testcase) # for target.path and installTestHelperApp()
installTestHelperApp("../copier/copier",copier,copier)
installTestHelperApp("../paster/paster",paster,paster)
