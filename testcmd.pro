TEMPLATE = app
TARGET = testcmd
CONFIG = c99 link_pkgconfig
DEFINES = _GNU_SOURCE bool=BOOL true=TRUE false=FALSE
INCLUDEPATH =
PKGCONFIG =

PKGCONFIG += tinyc
#PKGCONFIG += dbus-1
KGCONFIG += gio-2.0
PKGCONFIG += glib-2.0
#PKGCONFIG += gumbo
#PKGCONFIG += libcurl
#PKGCONFIG += libnotify
#PKGCONFIG += libusb
#PKGCONFIG += libxml-2.0
#PKGCONFIG += polkit-gobject-1


SOURCES = \
    glib/content_type.c \
    glib/gfile.c \
    glib/gfilemonitor1.c \
    glib/gfilemonitor2.c \
    glib/gkeyfile.c \
    glib/libnotify.c \
    libgd/colorswap.c \
    libgd/matrix.c \
    libgd/resize.c \
    other/cpu_count.c \
    other/desktop_edit.c \
    other/dnd_listbox.c \
    other/file_whileread.c \
    other/func_execvp.c \
    other/func_fgets.c \
    other/func_fnmatch.c \
    other/html_edit.c \
    other/is_wireless.c \
    other/kebek_list.c \
    other/lib_xml2.c \
    other/pipe_select.c \
    other/str_sort.c \
    other/sys_cpuusage.c \
    other/sys_getpid.c \
    other/sys_netinterface.c \
    other/sys_polkit.c \
    other/sys_timeout.c \
    other/syslog.c \
    other/test_autofree.c \
    time/func_get_localtime.c \
    time/func_localtime.c \
    time/func_strptime.c \
    time/sys_microseconds.c \
    time/sys_timediff.c \
    tinyc/c_args.c \
    tinyc/c_autofree.c \
    tinyc/c_autofree_test.c \
    tinyc/cdirparser.c \
    tinyc/cfile_read.c \
    tinyc/cfile_readwrite.c \
    tinyc/cfileinfo.c \
    tinyc/cprocess.c \
    tinyc/cregexp.c \
    tinyc/file_getline.c \
    tinyc/file_read.c \
    tinyc/str_getlineptr.c \
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
    0Temp.c \
    main.c \

DISTFILES = \
    glib/keyfile.ini \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


