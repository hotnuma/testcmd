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
    samples/cfile_write.cpp \
    samples/cprocess.cpp \
    samples/cregexp.cpp \
    samples/default.cpp \
    samples/pipe_select.cpp \
    samples/testout.cpp \
    samples/while_read.cpp

DISTFILES += \
    License.txt \
    Readme.txt \
    meson.build \
    install.sh \
    readme.md


