TEMPLATE = app
TARGET = testcmd
CONFIG = c99 link_pkgconfig
DEFINES = _GNU_SOURCE
INCLUDEPATH =
PKGCONFIG =

#PKGCONFIG += dbus-1
#PKGCONFIG += libusb
#PKGCONFIG += libxml-2.0

PKGCONFIG += tinyc
PKGCONFIG += gumbo
#PKGCONFIG += polkit-gobject-1
#PKGCONFIG += glib-2.0
#PKGCONFIG += gio-2.0

SOURCES = \
    examples/c_args.c \
    examples/c_autofree.c \
    examples/cdirparser.c \
    examples/cfile_read.c \
    examples/cfile_readwrite.c \
    examples/cprocess.c \
    examples/cregexp.c \
    examples/func_fgets.c \
    examples/func_file_getline.c \
    examples/func_file_read.c \
    examples/func_get_localtime.c \
    examples/func_str_getlineptr.c \
    examples/func_str_getpart.c \
    examples/sys_cpuload.c \
    examples/sys_log.c \
    examples/sys_timediff.c \
    0Temp.c \
    main.c

DISTFILES = \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


