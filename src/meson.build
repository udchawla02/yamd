lib_sources = [
    'hello.cpp',
    #'milestone2_verlet.cpp',
    'milestone3_verlet.cpp',
    'lj_direct_summation.cpp',
    'xyz.cpp'
]

lib_headers = [
    'hello.h',
    'types.h',
    'verlet.h',
    'atoms.h',
    'lj_direct_summation.h',
    'xyz.h'
]

lib = static_library(
    'lib',  # Unique name
    sources: lib_sources,
    include_directories: include_directories('.'),
    dependencies: [eigen_dep, mpi_dep]
)

lib_incdirs = include_directories('.')
