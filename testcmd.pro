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
    samples/c_args.c \
    samples/c_autofree.c \
    samples/cdirparser.c \
    samples/cfile_read.c \
    samples/cfile_readwrite.c \
    samples/cprocess.c \
    samples/func_fgets.c \
    samples/func_file_getline.c \
    samples/func_file_read.c \
    samples/func_str_getlineptr.c \
    samples/func_str_getpart.c \
    samples/lib_xml2.c \
    samples/sys_asound.c \
    samples/sys_cpuload.c \
    samples/sys_log.c \
    samples/sys_netinterface.c \
    samples/sys_netusage.c \
    samples/sys_timediff.c \
    samples/sys_usblist.c \
    0Temp.c \
    main.c

DISTFILES = \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


