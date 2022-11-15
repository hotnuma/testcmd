TEMPLATE = app
TARGET = testcmd
CONFIG = c++11
DEFINES =
INCLUDEPATH =

CONFIG += link_pkgconfig
PKGCONFIG = dbus-1

SOURCES = \
    0Temp.cpp \
    main.cpp \

DISTFILES += \
    install.sh \
    License.txt \
    meson.build \
    Readme.md \


