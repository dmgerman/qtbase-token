#####################################################################
# Main projectfile
#####################################################################

CONFIG += ordered
TEMPLATE = subdirs

cross_compile: CONFIG += nostrip

module_qtbase_tests.subdir = tests
module_qtbase_tests.target = module-qtbase-tests
module_qtbase_tests.depends = module_qtbase_src
module_qtbase_tests.CONFIG = no_default_install

#process the projects
PROJECTS=$$eval($$list($$lower($$unique(QT_BUILD_PARTS))))
# note that the order matters for these blocks!
contains(PROJECTS, qmake) {
    PROJECTS -= qmake
    # nothing to be done
}
contains(PROJECTS, libs) {
    PROJECTS -= libs
    include(src/src.pro)
}
contains(PROJECTS, examples) {
    PROJECTS -= examples
    SUBDIRS += examples
}
contains(PROJECTS, tests) {
    PROJECTS -= tests
    SUBDIRS += module_qtbase_tests
}
!isEmpty(PROJECTS) {
    message(Unknown PROJECTS: $$PROJECTS)
}

confclean.depends += clean
confclean.commands =
unix {
  confclean.commands += (cd config.tests/unix/stl && $(MAKE) distclean); \
			(cd config.tests/unix/endian && $(MAKE) distclean); \
			(cd config.tests/unix/ipv6 && $(MAKE) distclean); \
			(cd config.tests/unix/largefile && $(MAKE) distclean); \
			(cd config.tests/unix/ptrsize && $(MAKE) distclean); \
			(cd config.tests/x11/notype && $(MAKE) distclean); \
			(cd config.tests/unix/getaddrinfo && $(MAKE) distclean); \
			(cd config.tests/unix/cups && $(MAKE) distclean); \
			(cd config.tests/unix/psql && $(MAKE) distclean); \
			(cd config.tests/unix/mysql && $(MAKE) distclean); \
 	 		(cd config.tests/unix/mysql_r && $(MAKE) distclean); \
			(cd config.tests/unix/nis && $(MAKE) distclean); \
			(cd config.tests/unix/nix && $(MAKE) distclean); \
			(cd config.tests/unix/iodbc && $(MAKE) distclean); \
			(cd config.tests/unix/odbc && $(MAKE) distclean); \
			(cd config.tests/unix/oci && $(MAKE) distclean); \
			(cd config.tests/unix/tds && $(MAKE) distclean); \
			(cd config.tests/unix/db2 && $(MAKE) distclean); \
			(cd config.tests/unix/ibase && $(MAKE) distclean); \
			(cd config.tests/unix/ipv6ifname && $(MAKE) distclean); \
			(cd config.tests/unix/zlib && $(MAKE) distclean); \
			(cd config.tests/unix/sqlite2 && $(MAKE) distclean); \
			(cd config.tests/unix/libjpeg && $(MAKE) distclean); \
			(cd config.tests/unix/libpng && $(MAKE) distclean); \
			(cd config.tests/x11/xcursor && $(MAKE) distclean); \
			(cd config.tests/x11/xrender && $(MAKE) distclean); \
			(cd config.tests/x11/xrandr && $(MAKE) distclean); \
			(cd config.tests/x11/xkb && $(MAKE) distclean); \
			(cd config.tests/x11/xinput && $(MAKE) distclean); \
			(cd config.tests/x11/fontconfig && $(MAKE) distclean); \
			(cd config.tests/x11/xinerama && $(MAKE) distclean); \
			(cd config.tests/x11/sm && $(MAKE) distclean); \
			(cd config.tests/x11/xshape && $(MAKE) distclean); \
			(cd config.tests/x11/opengl && $(MAKE) distclean); \
                        $(DEL_FILE) config.tests/.qmake.cache; \
			$(DEL_FILE) src/corelib/global/qconfig.h; \
			$(DEL_FILE) src/corelib/global/qconfig.cpp; \
			$(DEL_FILE) mkspecs/qconfig.pri; \
			$(DEL_FILE) mkspecs/qmodule.pri; \
			$(DEL_FILE) .qmake.cache; \
 			(cd qmake && $(MAKE) distclean);
}
win32 {
  confclean.commands += -$(DEL_FILE) src\\corelib\\global\\qconfig.h $$escape_expand(\\n\\t) \
			-$(DEL_FILE) src\\corelib\\global\\qconfig.cpp $$escape_expand(\\n\\t) \
			-$(DEL_FILE) mkspecs\\qconfig.pri $$escape_expand(\\n\\t) \
			-$(DEL_FILE) mkspecs\\qmodule.pri $$escape_expand(\\n\\t) \
			-$(DEL_FILE) .qmake.cache $$escape_expand(\\n\\t) \
			(cd qmake && $(MAKE) distclean)
}
QMAKE_EXTRA_TARGETS += confclean
qmakeclean.commands += (cd qmake && $(MAKE) clean)
QMAKE_EXTRA_TARGETS += qmakeclean
CLEAN_DEPS += qmakeclean

CONFIG -= qt

### installations ####

#qmake
qmake.path = $$[QT_HOST_BINS]
win32 {
   qmake.files=$$QT_BUILD_TREE/bin/qmake.exe
} else {
   qmake.files=$$QT_BUILD_TREE/bin/qmake
}
INSTALLS += qmake

#syncqt
syncqt.path = $$[QT_HOST_BINS]
syncqt.files=$$QT_BUILD_TREE/bin/syncqt
win32:syncqt.files=$$QT_BUILD_TREE/bin/syncqt.bat
INSTALLS += syncqt

#qtmodule-configtests
configtests.path = $$[QT_HOST_BINS]
configtests.files=$$QT_BUILD_TREE/bin/qtmodule-configtests
INSTALLS += configtests

#mkspecs
mkspecs.path = $$[QT_HOST_DATA]/mkspecs
mkspecs.files=$$QT_BUILD_TREE/mkspecs/qconfig.pri $$QT_BUILD_TREE/mkspecs/qmodule.pri $$files($$QT_SOURCE_TREE/mkspecs/*)
mkspecs.files -= $$QT_SOURCE_TREE/mkspecs/modules
unix { 
   DEFAULT_QMAKESPEC = $$QMAKESPEC
   DEFAULT_QMAKESPEC ~= s,^.*mkspecs/,,g
   mkspecs.commands += $(DEL_FILE) $(INSTALL_ROOT)$$mkspecs.path/default; $(SYMLINK) $$DEFAULT_QMAKESPEC $(INSTALL_ROOT)$$mkspecs.path/default
   mkspecs.files -= $$QT_SOURCE_TREE/mkspecs/default
}
win32:!equals(QT_BUILD_TREE, $$QT_SOURCE_TREE) {
    # When shadow building on Windows, the default mkspec only exists in the build tree.
    mkspecs.files += $$QT_BUILD_TREE/mkspecs/default
}
INSTALLS += mkspecs

OTHER_FILES += \
    configure \
    header.BSD \
    header.FDL \
    header.LGPL \
    header.LGPL-ONLY \
    sync.profile
