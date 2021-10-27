TEMPLATE = app
TARGET = testcmd
CONFIG = c++11
DEFINES =
INCLUDEPATH =

CONFIG += link_pkgconfig
PKGCONFIG = dbus-1

SOURCES = \
    0Temp.cpp \
    main.cpp \
    samples/cdirparser.cpp \
    samples/cfile_read.cpp \
    samples/cfile_write.cpp \
    samples/cprocess.cpp \
    samples/cregexp.cpp \
    samples/dbus.cpp \
    samples/default.cpp \
    samples/pipe_select.cpp \
    samples/strGetLine.cpp \
    samples/strGetLinePtr.cpp \
    samples/testout.cpp \
    samples/while_read.cpp

DISTFILES += \
    License.txt \
    Readme.txt \
    meson.build \
    install.sh \
    samples/testout.sh


