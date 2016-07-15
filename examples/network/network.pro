TEMPLATE      = subdirs
SUBDIRS       = \
                dnslookup \
                download \
                downloadmanager

!contains(QT_CONFIG, no-gui) {
    SUBDIRS +=  \
                blockingfortuneclient \
                broadcastreceiver \
                broadcastsender \
                fortuneclient \
                fortuneserver \
                http \
                loopback \
                threadedfortuneserver \
                googlesuggest \
                torrent \
                bearermonitor \
                multicastreceiver \
                multicastsender

    # no QProcess
    !vxworks:!qnx:SUBDIRS += network-chat

    contains(QT_CONFIG, openssl):SUBDIRS += securesocketclient
    contains(QT_CONFIG, openssl-linked):SUBDIRS += securesocketclient
}


# install
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS network.pro README
sources.path = $$[QT_INSTALL_EXAMPLES]/qtbase/network
INSTALLS += sources

QT += widgets
