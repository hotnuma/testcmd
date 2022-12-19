TEMPLATE = app
TARGET = testcmd
CONFIG = c99 link_pkgconfig
DEFINES =
INCLUDEPATH =

#DEFINES += GTK
#PKGCONFIG += gtk+-3.0
#PKGCONFIG += dbus-1
#PKGCONFIG += glib-2.0
#PKGCONFIG += libxml-2.0

PKGCONFIG += tinyc

SOURCES = \
    0Temp.c \
    main.c \
    samples/auto_free.c \
    samples/c_while_read.c \
    samples/cdirparser.c \
    samples/cfile_read.c \
    samples/cfile_readwrite.c \
    samples/cprocess.c \
    samples/cregexp.c \
    samples/dbus_example.c \
    samples/dbus_notifyd.c \
    samples/find_prc.c \
    samples/func_getCurrentTime.c \
    samples/func_strFileRead.c \
    samples/func_strGetLine.c \
    samples/func_strGetLinePtr.c \
    samples/func_strGetPart.c \
    samples/lib_xml2.c \
    samples/list_words.c \
    samples/main.c \
    samples/pipe_select.c \
    samples/sys_asound.c \
    samples/sys_gudev.c \
    samples/sys_iniparse.c \
    samples/sys_syslog.c \
    samples/sys_time.c \
    samples/sys_usblist.c

DISTFILES += \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \
    samples/sys_iniparse.ini


