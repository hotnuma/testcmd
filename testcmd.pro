TEMPLATE = app
TARGET = testcmd
CONFIG = c++11
DEFINES =
INCLUDEPATH =

CONFIG += link_pkgconfig

PKGCONFIG += glib-2.0
#PKGCONFIG += gtk+-3.0
#PKGCONFIG += dbus-1
#DEFINES += GTK

SOURCES = \
    0Temp.cpp \
    main.cpp \
    samples/cdirparser.cpp \
    samples/cfile_read.cpp \
    samples/cfile_readwrite.cpp \
    samples/cprocess.cpp \
    samples/cregexp.cpp \
    samples/find_prc.cpp \
    samples/getCurrentTime.cpp \
    samples/main.cpp \
    samples/pipe_select.cpp \
    samples/proc_asound.cpp \
    samples/strFileRead.cpp \
    samples/strGetLine.cpp \
    samples/strGetLinePtr.cpp \
    samples/strGetPart.cpp \
    samples/time.cpp \
    samples/usb_list.cpp

DISTFILES += \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


