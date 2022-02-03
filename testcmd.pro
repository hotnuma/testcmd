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
    samples1/main.cpp \
    samples1/therm_beta.cpp \
    samples1/therm_steinharthart.cpp \
    samples2/cdirparser.cpp \
    samples2/cfile_read.cpp \
    samples2/cfile_readwrite.cpp \
    samples2/cprocess.cpp \
    samples2/cregexp.cpp \
    samples2/dbus.cpp \
    samples2/find_prc.cpp \
    samples2/getCurrentTime.cpp \
    samples2/pipe_select.cpp \
    samples2/proc_asound.cpp \
    samples2/strGetLine.cpp \
    samples2/strGetLinePtr.cpp \
    samples2/strGetPart.cpp \
    samples2/testout.cpp \
    samples2/time.cpp \
    samples2/usb_list.cpp \
    samples2/while_read.cpp

DISTFILES += \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


