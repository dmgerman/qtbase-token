TEMPLATE = subdirs

TOOLS_SUBDIRS = src_tools_bootstrap src_tools_moc src_tools_rcc src_tools_qdoc
contains(QT_CONFIG, dbus): TOOLS_SUBDIRS += src_tools_qdbusxml2cpp src_tools_qdbuscpp2xml
!contains(QT_CONFIG, no-gui): TOOLS_SUBDIRS += src_tools_uic
# Set subdir and respective target name
src_tools_bootstrap.subdir = $$PWD/bootstrap
src_tools_bootstrap.target = sub-tools-bootstrap
src_tools_moc.subdir = $$PWD/moc
src_tools_moc.target = sub-moc
src_tools_rcc.subdir = $$PWD/rcc
src_tools_rcc.target = sub-rcc
src_tools_uic.subdir = $$PWD/uic
src_tools_uic.target = sub-uic
src_tools_qdoc.subdir = $$QT_SOURCE_TREE/src/tools/qdoc
src_tools_qdoc.target = sub-qdoc
contains(QT_CONFIG, dbus) {
    src_tools_qdbusxml2cpp.subdir = $$QT_SOURCE_TREE/src/tools/qdbusxml2cpp
    src_tools_qdbusxml2cpp.target = sub-qdbusxml2cpp
    src_tools_qdbuscpp2xml.subdir = $$QT_SOURCE_TREE/src/tools/qdbuscpp2xml
    src_tools_qdbuscpp2xml.target = sub-qdbuscpp2xml
}

!wince*:!ordered {
    # Set dependencies for each subdir
    src_tools_moc.depends = src_tools_bootstrap
    src_tools_rcc.depends = src_tools_bootstrap
    src_tools_uic.depends = src_tools_bootstrap
    src_tools_qdoc.depends = src_tools_bootstrap
    contains(QT_CONFIG, dbus) {
        src_tools_qdbusxml2cpp.depends = src_tools_bootstrap
        src_tools_qdbuscpp2xml.depends = src_tools_bootstrap
    }
}

# Special handling, depending on type of project, if it used debug/release or only has one configuration
EXTRA_DEBUG_TARGETS =
EXTRA_RELEASE_TARGETS =
for(subname, TOOLS_SUBDIRS) {
    subdir = $$subname
    !isEmpty($${subname}.subdir):subdir = $$eval($${subname}.subdir)
    subpro = $$subdir/$${basename(subdir)}.pro
    !exists($$subpro):next()
    subtarget = $$replace(subdir, [^A-Za-z0-9], _)
    reg_src = $$replace(QT_SOURCE_TREE, \\\\, \\\\)
    subdir = $$replace(subdir, $$reg_src, $$QT_BUILD_TREE)
    subdir = $$replace(subdir, /, $$QMAKE_DIR_SEP)
    subdir = $$replace(subdir, \\\\, $$QMAKE_DIR_SEP)
    include($$subpro, SUB)
    !isEqual(subname, src_tools_bootstrap):if(isEqual(SUB.TEMPLATE, lib) | isEqual(SUB.TEMPLATE, subdirs)):!separate_debug_info {
        #debug
        debug-$${subtarget}.depends = $${subdir}$${QMAKE_DIR_SEP}$(MAKEFILE) $$EXTRA_DEBUG_TARGETS
        debug-$${subtarget}.commands = (cd $$subdir && $(MAKE) -f $(MAKEFILE) debug)
        EXTRA_DEBUG_TARGETS += debug-$${subtarget}
        QMAKE_EXTRA_TARGETS += debug-$${subtarget}
        #release
        release-$${subtarget}.depends = $${subdir}$${QMAKE_DIR_SEP}$(MAKEFILE) $$EXTRA_RELEASE_TARGETS
        release-$${subtarget}.commands = (cd $$subdir && $(MAKE) -f $(MAKEFILE) release)
        EXTRA_RELEASE_TARGETS += release-$${subtarget}
        QMAKE_EXTRA_TARGETS += release-$${subtarget}
    } else { #do not have a real debug target/release
        #debug
        debug-$${subtarget}.depends = $${subdir}$${QMAKE_DIR_SEP}$(MAKEFILE) $$EXTRA_DEBUG_TARGETS
        debug-$${subtarget}.commands = (cd $$subdir && $(MAKE) -f $(MAKEFILE) first)
        EXTRA_DEBUG_TARGETS += debug-$${subtarget}
        QMAKE_EXTRA_TARGETS += debug-$${subtarget}
        #release
        release-$${subtarget}.depends = $${subdir}$${QMAKE_DIR_SEP}$(MAKEFILE) $$EXTRA_RELEASE_TARGETS
        release-$${subtarget}.commands = (cd $$subdir && $(MAKE) -f $(MAKEFILE) first)
        EXTRA_RELEASE_TARGETS += release-$${subtarget}
        QMAKE_EXTRA_TARGETS += release-$${subtarget}
    }
}

SUBDIRS = $$TOOLS_SUBDIRS $$SUBDIRS
isEqual(TARGET,tools): SUBDIRS += $$SRC_SUBDIRS
