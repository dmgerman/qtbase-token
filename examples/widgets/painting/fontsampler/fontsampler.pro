FORMS     = mainwindowbase.ui
HEADERS   = mainwindow.h
SOURCES   = main.cpp \
            mainwindow.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/painting/fontsampler
INSTALLS += target

QT += widgets
!isEmpty(QT.printsupport.name): QT += printsupport
