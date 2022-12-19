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
    samples/cfile_read.c \
    samples/list_words.c \
    samples/main.c \

DISTFILES += \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


