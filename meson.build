project(
    'testcmd',
    ['c'],
    version : '1.0',
    license : 'GPL-2.0',
    default_options : [
        'c_std=c99',
    ],
)

c_args = [
    '-Wall',
    '-Wextra',
    '-O2',
]

# examples
#dependency('gtk+-3.0'),
#dependency('libpcre'),
#dependency('libusb'),
#dependency('libxml-2.0'),
#dependency('dbus-1'),
#dependency('gudev-1.0'),

app_deps = [
    dependency('tinyc'),
    dependency('glib-2.0'),
    dependency('gio-2.0'),
]

app_src = [
    'main.c',
]

executable(
    meson.project_name(),
    c_args : c_args,
    dependencies : app_deps,
    sources : app_src,
    install : false,
)


