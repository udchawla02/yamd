test_sources = [
	'gtest_mpi_main.cpp',
	'test_hello_world.cpp',
	#'test_milestone2_verlet.cpp',
	'test_milestone3_verlet.cpp',
	'test_lj_direct_summation.cpp'
]

# Specify that we don't want the main function from gtest
gtest_dep = dependency('gtest', main : false)

tests_exe = executable(
	'tests',
	test_sources,
	include_directories : [lib_incdirs],
	link_with : [lib],
	dependencies : [gtest_dep, eigen_dep, mpi_dep]
)

test('unit', tests_exe)
