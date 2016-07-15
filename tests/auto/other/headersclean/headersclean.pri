# The headersclean test attempts to ensure all public Qt headers
# abide by various rules.
#
# To reuse this test outside of the qtbase module,
# include this .pri and create a qt_headersclean_headers.h which includes
# the headers you'd like to test.

*-g++*: QMAKE_CXXFLAGS += -W -Wall -Wextra -Werror

# The flags here come from http://wiki.qt-project.org/Coding_Conventions#Conventions_for_public_header_files
# -Wold-style-cast cannot be used, /usr/include/bits/byteswap.h defines the macro bswap_16 using C style casts :(
# -Wfloat-equal cannot be used, qrect.h and qvector2d.h do exact comparisons in isNull and operator==. Would need #pragmas.
*-g++*: QMAKE_CXXFLAGS += -Wshadow -Wundef

# Other nice flags
*-g++*: QMAKE_CXXFLAGS += -Wnon-virtual-dtor -ansi -Wcast-align -Wchar-subscripts -Wpointer-arith -Wformat-security

# Enable pedantic mode, but accept variadic macros and 'long long' usage.
*-g++*: QMAKE_CXXFLAGS += -Wno-long-long -Wno-variadic-macros -pedantic-errors

contains(QT_ARCH,arm)|contains(QT_ARCH,mips) {
    # There are outstanding alignment issues in some container classes.
    *-g++*:QMAKE_CXXFLAGS -= -Wcast-align
}

QMAKE_CXXFLAGS += -DQT_NO_CAST_TO_ASCII \
                  -DQT_NO_CAST_FROM_ASCII \
                  -DQT_STRICT_ITERATORS \
                  -DQT_NO_URL_CAST_FROM_STRING \
                  -DQT_NO_CAST_FROM_BYTEARRAY \
                  -DQT_NO_KEYWORDS \
                  -DQT_USE_FAST_CONCATENATION \
                  -DQT_USE_FAST_OPERATOR_PLUS

TARGET = tst_headersclean
SOURCES += $$PWD/tst_headersclean.cpp
HEADERS += $$PWD/tst_headersclean.h

# qt_headersclean_headers.h should be alongside the .pro file
INCLUDEPATH += $$_PRO_FILE_PWD_
