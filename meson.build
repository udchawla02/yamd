project(
    'my-fantastic-project',
    ['c', 'cpp'],
    default_options : ['cpp_std=c++17'],
    version : '0.1'
)

eigen_dep = dependency('eigen3', version: '>=3.4.0', fallback: ['eigen', 'eigen_dep'])
mpi_dep = dependency('mpi', language: 'cpp')
gtest_dep = dependency('gtest', main: true, fallback: ['gtest', 'gtest_main_dep'])

subdir('src')
subdir('milestones')
subdir('tests')
