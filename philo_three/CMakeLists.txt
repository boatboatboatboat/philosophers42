project (philo_three)
cmake_minimum_required(VERSION 3.15)

aux_source_directory(src VAR)

include_directories(include)
add_executable(philo_tree_cmake ${VAR})