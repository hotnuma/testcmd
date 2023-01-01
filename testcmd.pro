TEMPLATE = app
TARGET = testcmd
CONFIG = c99 link_pkgconfig
DEFINES =
#DEFINES += GTK
INCLUDEPATH =

PKGCONFIG += gtk+-3.0
#PKGCONFIG += dbus-1
#PKGCONFIG += glib-2.0
#PKGCONFIG += libxml-2.0

PKGCONFIG += tinyc

SOURCES = \
    0Temp.c \
    main.c \

DISTFILES += \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


