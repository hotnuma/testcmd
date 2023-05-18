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
    main.c \
    samples1/c_args.c \
    samples1/c_autofree.c \
    samples1/c_autofree_test.c \
    samples1/cdirparser.c \
    samples1/cfile_read.c \
    samples1/cfile_readwrite.c \
    samples1/cprocess.c \
    samples1/cregexp.c \
    samples1/func_fgets.c \
    samples1/func_file_getline.c \
    samples1/func_file_read.c \
    samples1/func_get_localtime.c \
    samples1/func_str_getlineptr.c \
    samples1/func_str_getpart.c \
    samples1/sys_cmdline.c \
    samples1/sys_getpid.c \
    samples1/sys_timediff.c \
    samples2/desktop_edit.c \
    samples2/file_whileread.c \
    samples2/finddate.c \
    samples2/func_str_getpart2.c \
    samples2/glib_keyfile.c \
    samples2/is_wireless.c \
    samples2/kebek_list.c \
    samples2/lib_xml2.c \
    samples2/pipe_select.c \
    samples2/sys_cpuusage.c \
    samples2/sys_filemonitor.c \
    samples2/sys_libnotify.c \
    samples2/sys_netinterface.c \
    samples2/sys_polkit.c \
    samples2/sys_timeout.c \
    samples2/syslog.c \
    samples2/test_autofree.c

DISTFILES = \
    install.sh \
    License.txt \
    meson.build \
    Readme.md


