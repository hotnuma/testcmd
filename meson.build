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

#link_args = [
#    '-static',
#    '-Wl,-s'
#]

app_deps = [
    dependency('libpcre'),
    dependency('tinycpp', static : true),
]

app_src = [
    'main.cpp',
]

executable(
    'testcmd',
    cpp_args : cpp_args,
    dependencies : app_deps,
    sources : app_src,
#    link_args : link_args,
#    link_with : dependency('tinycpp'),
)


