project(
    'testcmd',
    ['cpp'],
    version : '1.0',
    license : 'GPL-2.0',
    default_options : [
        'cpp_std=c++11',
    ],
)

cpp_args = [
    '-Wall',
    '-fno-rtti',
    '-fno-exceptions',
    '-O2',
]

cc = meson.get_compiler('cpp')

tinycpp_dep = declare_dependency(
    include_directories : include_directories('.'),
    dependencies : cc.find_library('tinycpp'),
)

app_deps = [
    dependency('libpcre'),
    dependency('dbus-1'),
    tinycpp_dep,
#    dependency('tinycpp', static : true),
]

app_src = [
    'main.cpp',
]

executable(
    'testcmd',
    cpp_args : cpp_args,
    dependencies : app_deps,
    sources : app_src,
)


