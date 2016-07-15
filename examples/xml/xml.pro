TEMPLATE      = subdirs
SUBDIRS       = htmlinfo \
                xmlstreamlint

!contains(QT_CONFIG, no-widgets) {
    SUBDIRS +=  dombookmarks \
                rsslisting \
                saxbookmarks \
                streambookmarks
}


# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtbase/xml
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS xml.pro README
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/xml
INSTALLS += target sources
