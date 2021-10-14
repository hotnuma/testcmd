TEMPLATE = app
TARGET = testcmd
CONFIG = c++11
DEFINES =
INCLUDEPATH =

HEADERS = \
    other/stristr.h

SOURCES = \
    0Temp.cpp \
    main.cpp \
    samples/cdirparser.cpp \
    samples/cfile_read.cpp \
    samples/cregexp.cpp \
    samples/default.cpp \
    samples/getline.cpp \
    samples/getlineptr.cpp \
    samples/parselist.cpp \
    samples/popen.cpp \
    samples/testout.cpp \
    samples/while_fread.cpp

DISTFILES += \
    meson.build \
    install.sh \


