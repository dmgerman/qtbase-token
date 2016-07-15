TEMPLATE = subdirs

SUBDIRS += \
    corelib \
    dbus \
    gui \
    network \
    opengl \
    sql \
    testlib \
    tools \
    xml \
    concurrent \
    other \
    widgets \
    printsupport \

cross_compile:                              SUBDIRS -= tools
!contains(QT_CONFIG, opengl):               SUBDIRS -= opengl
!unix|embedded|!contains(QT_CONFIG, dbus):  SUBDIRS -= dbus
contains(QT_CONFIG, no-widgets):            SUBDIRS -= widgets

# disable 'make check' on Mac OS X for the following subdirs for the time being
mac {
    network.CONFIG += no_check_target
}

!contains(QT_CONFIG, concurrent): SUBDIRS -= concurrent

