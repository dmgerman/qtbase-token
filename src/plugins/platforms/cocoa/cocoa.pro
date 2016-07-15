TARGET = qcocoa
load(qt_plugin)
DESTDIR = $$QT.gui.plugins/platforms

OBJECTIVE_SOURCES += main.mm \
    qcocoaintegration.mm \
    qcocoatheme.mm \
    qcocoabackingstore.mm \
    qcocoawindow.mm \
    qnsview.mm \
    qnsviewaccessibility.mm \
    qcocoaautoreleasepool.mm \
    qnswindowdelegate.mm \
    qcocoaglcontext.mm \
    qcocoanativeinterface.mm \
    qcocoaeventdispatcher.mm \
    qcocoamenuloader.mm \
    qcocoaapplicationdelegate.mm \
    qcocoaapplication.mm \
    qcocoamenu.mm \
    qmenu_mac.mm \
    qcocoahelpers.mm \
    qmultitouch_mac.mm \
    qcocoaaccessibilityelement.mm \
    qcocoaaccessibility.mm \
    qcocoacolordialoghelper.mm \
    qcocoafiledialoghelper.mm \
    qcocoafontdialoghelper.mm \
    qcocoacursor.mm \
    qcocoadrag.mm \
    qmacclipboard.mm \
    qmacmime.mm \
    qcocoasystemsettings.mm \
    qcocoainputcontext.mm \
    qpaintengine_mac.mm \
    qprintengine_mac.mm \

HEADERS += qcocoaintegration.h \
    qcocoatheme.h \
    qcocoabackingstore.h \
    qcocoawindow.h \
    qnsview.h \
    qcocoaautoreleasepool.h \
    qnswindowdelegate.h \
    qcocoaglcontext.h \
    qcocoanativeinterface.h \
    qcocoaeventdispatcher.h \
    qcocoamenuloader.h \
    qcocoaapplicationdelegate.h \
    qcocoaapplication.h \
    qcocoamenu.h \
    qmenu_mac.h \
    qcocoahelpers.h \
    qmultitouch_mac_p.h \
    qcocoaaccessibilityelement.h \
    qcocoaaccessibility.h \
    qcocoacolordialoghelper.h \
    qcocoafiledialoghelper.h \
    qcocoafontdialoghelper.h \
    qcocoacursor.h \
    qcocoadrag.h \
    qmacclipboard.h \
    qmacmime.h \
    qcocoasystemsettings.h \
    qcocoainputcontext.h \
    qpaintengine_mac_p.h \
    qprintengine_mac_p.h \

FORMS += $$PWD/../../../widgets/dialogs/qfiledialog.ui
RESOURCES += qcocoaresources.qrc

LIBS += -framework Cocoa

QT += core-private gui-private widgets-private platformsupport-private printsupport

OTHER_FILES += cocoa.json
target.path += $$[QT_INSTALL_PLUGINS]/platforms
INSTALLS += target

# Build the release libqcocoa.dylib only, skip the debug version.
# The Qt plugin loader will dlopen both if found, causing duplicate
# Objective-c class definitions for the classes defined in the plugin.
contains(QT_CONFIG,release):CONFIG -= debug

# Acccessibility debug support
# DEFINES += QT_COCOA_ENABLE_ACCESSIBILITY_INSPECTOR
# include ($$PWD/../../../../util/accessibilityinspector/accessibilityinspector.pri)

# Window debug support
#DEFINES += QT_COCOA_ENABLE_WINDOW_DEBUG
