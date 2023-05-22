TEMPLATE = app
TARGET = testcmd
CONFIG = c99 link_pkgconfig
DEFINES = _GNU_SOURCE
INCLUDEPATH =
PKGCONFIG =

PKGCONFIG += tinyc
#PKGCONFIG += dbus-1
#PKGCONFIG += glib-2.0
#PKGCONFIG += gio-2.0
#PKGCONFIG += gumbo
#PKGCONFIG += libcurl
PKGCONFIG += libnotify
#PKGCONFIG += libusb
#PKGCONFIG += libxml-2.0
#PKGCONFIG += polkit-gobject-1


SOURCES = \
    0Temp.c \
    exp_glib/content_type.c \
    exp_glib/gfile.c \
    exp_glib/gfilemonitor.c \
    exp_glib/gkeyfile.c \
    exp_glib/libnotify.c \
    exp_tinyc/c_args.c \
    exp_tinyc/c_autofree.c \
    exp_tinyc/c_autofree_test.c \
    exp_tinyc/cdirparser.c \
    exp_tinyc/cfile_read.c \
    exp_tinyc/cfile_readwrite.c \
    exp_tinyc/cprocess.c \
    exp_tinyc/cregexp.c \
    exp_tinyc/func_file_getline.c \
    exp_tinyc/func_file_read.c \
    exp_tinyc/func_get_localtime.c \
    exp_tinyc/func_str_getlineptr.c \
    exp_tinyc/func_str_getpart.c \
    exp_tinyc/sys_cmdline.c \
    main.c \
    tools/lib_curl.c \
    tools/mdspaces.c \
    tools/sys_asound.c \
    tools/sys_cpuload.c \
    tools/sys_dirstat.c \
    tools/sys_find_prc.c \
    tools/sys_log.c \
    tools/sys_microseconds.c \
    tools/sys_netlist.c \
    tools/sys_netusage.c \
    tools/sys_usblist.c \
    tools/testout.c \
    tools/wordparser.c

DISTFILES = \
    install.sh \
    License.txt \
    meson.build \
    Readme.md


