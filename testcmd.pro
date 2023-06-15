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
    glib/content_type.c \
    glib/gfile.c \
    glib/gfilemonitor.c \
    glib/gkeyfile.c \
    glib/libnotify.c \
    main.c \
    other/desktop_edit.c \
    other/dnd_listbox.c \
    other/file_whileread.c \
    other/func_fgets.c \
    other/func_fnmatch.c \
    other/is_wireless.c \
    other/kebek_list.c \
    other/lib_xml2.c \
    other/pipe_select.c \
    other/sys_cpuusage.c \
    other/sys_getpid.c \
    other/sys_netinterface.c \
    other/sys_polkit.c \
    other/sys_timeout.c \
    other/syslog.c \
    other/test_autofree.c \
    time/finddate.c \
    time/func_get_localtime.c \
    time/func_strptime.c \
    time/sys_microseconds.c \
    time/sys_timediff.c \
    tinyc/c_args.c \
    tinyc/c_autofree.c \
    tinyc/c_autofree_test.c \
    tinyc/cdirparser.c \
    tinyc/cfile_read.c \
    tinyc/cfile_readwrite.c \
    tinyc/cprocess.c \
    tinyc/cregexp.c \
    tinyc/func_file_getline.c \
    tinyc/func_file_read.c \
    tinyc/func_str_getlineptr.c \
    tinyc/sys_cmdline.c \
    tools/lib_curl.c \
    tools/mdspaces.c \
    tools/sys_asound.c \
    tools/sys_cpuload.c \
    tools/sys_dirstat.c \
    tools/sys_find_prc.c \
    tools/sys_log.c \
    tools/sys_netlist.c \
    tools/sys_netusage.c \
    tools/sys_usblist.c \
    tools/testout.c \

DISTFILES = \
    glib/keyfile.ini \
    install.sh \
    License.txt \
    meson.build \
    Readme.md


