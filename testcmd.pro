TEMPLATE = app
TARGET = testcmd
CONFIG = c99 link_pkgconfig
DEFINES =
INCLUDEPATH =
PKGCONFIG =

#PKGCONFIG += dbus-1
#PKGCONFIG += libusb
#PKGCONFIG += libxml-2.0

PKGCONFIG += tinyc
#PKGCONFIG += glib-2.0
#PKGCONFIG += gio-2.0

SOURCES = \
    samples/cdirparser.c \
    samples/cfile_read.c \
    samples/cfile_readwrite.c \
    samples/cfile_words.c \
    samples/cprocess.c \
    0Temp.c \
    main.c \
    samples/find_prc.c \
    samples/func_file_getline.c \
    samples/func_file_read.c \
    samples/func_str_getlineptr.c \
    samples/func_str_getpart.c \
    samples/sys_usblist.c

DISTFILES = \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


