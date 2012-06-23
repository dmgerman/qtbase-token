TEMPLATE=subdirs
SUBDIRS=\
    qabstractfileengine \
    qbuffer \
    qdatastream \
    qdataurl \
    qdebug \
    qdir \
    qdiriterator \
    qfile \
    largefile \
    qfileinfo \
    qfilesystementry \
    qfilesystemwatcher \
    qiodevice \
    qipaddress \
    qnodebug \
    qprocess \
    qprocessenvironment \
    qresourceengine \
    qsettings \
    qstandardpaths \
    qtemporarydir \
    qtemporaryfile \
    qtextstream \
    qurl \
    qurlinternal \
    qurlquery \
    qwinoverlappedionotifier \

!win32|wince* {
    SUBDIRS -=\
        qwinoverlappedionotifier
}

!contains(QT_CONFIG, private_tests): SUBDIRS -= \
    qabstractfileengine \
    qfileinfo \
    qipaddress

win32:!contains(QT_CONFIG, private_tests): SUBDIRS -= \
    qfilesystementry
