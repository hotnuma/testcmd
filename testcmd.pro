TEMPLATE = app
TARGET = testcmd
CONFIG = c99 link_pkgconfig
DEFINES =
INCLUDEPATH =
PKGCONFIG =

PKGCONFIG += gtk+-3.0
#PKGCONFIG += glib-2.0
#PKGCONFIG += dbus-1
#PKGCONFIG += libxml-2.0

PKGCONFIG += tinyc

SOURCES = \
    samples/cdirparser.c \
    samples/cfile_read.c \
    samples/cfile_readwrite.c \
    samples/cfile_words.c \
    samples/cprocess.c \
    samples/func_cstr_fileread.c \
    samples/func_str_getline.c \
    0Temp.c \
    main.c \

DISTFILES += \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


