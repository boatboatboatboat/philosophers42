# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/boat/codam/philosophers/philo_one

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/boat/codam/philosophers/philo_one/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/philo_one_cmake.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo_one_cmake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo_one_cmake.dir/flags.make

CMakeFiles/philo_one_cmake.dir/src/do_eat.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/do_eat.c.o: ../src/do_eat.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo_one_cmake.dir/src/do_eat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/do_eat.c.o   -c /home/boat/codam/philosophers/philo_one/src/do_eat.c

CMakeFiles/philo_one_cmake.dir/src/do_eat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/do_eat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/do_eat.c > CMakeFiles/philo_one_cmake.dir/src/do_eat.c.i

CMakeFiles/philo_one_cmake.dir/src/do_eat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/do_eat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/do_eat.c -o CMakeFiles/philo_one_cmake.dir/src/do_eat.c.s

CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.o: ../src/do_sleep.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.o   -c /home/boat/codam/philosophers/philo_one/src/do_sleep.c

CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/do_sleep.c > CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.i

CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/do_sleep.c -o CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.s

CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.o: ../src/drop_forks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.o   -c /home/boat/codam/philosophers/philo_one/src/drop_forks.c

CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/drop_forks.c > CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.i

CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/drop_forks.c -o CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.s

CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.o: ../src/fake_trylock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.o   -c /home/boat/codam/philosophers/philo_one/src/fake_trylock.c

CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/fake_trylock.c > CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.i

CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/fake_trylock.c -o CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.s

CMakeFiles/philo_one_cmake.dir/src/gettime.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/gettime.c.o: ../src/gettime.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/philo_one_cmake.dir/src/gettime.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/gettime.c.o   -c /home/boat/codam/philosophers/philo_one/src/gettime.c

CMakeFiles/philo_one_cmake.dir/src/gettime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/gettime.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/gettime.c > CMakeFiles/philo_one_cmake.dir/src/gettime.c.i

CMakeFiles/philo_one_cmake.dir/src/gettime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/gettime.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/gettime.c -o CMakeFiles/philo_one_cmake.dir/src/gettime.c.s

CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.o: ../src/hecking_die.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.o   -c /home/boat/codam/philosophers/philo_one/src/hecking_die.c

CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/hecking_die.c > CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.i

CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/hecking_die.c -o CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.s

CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.o: ../src/init_mutex.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.o   -c /home/boat/codam/philosophers/philo_one/src/init_mutex.c

CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/init_mutex.c > CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.i

CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/init_mutex.c -o CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.s

CMakeFiles/philo_one_cmake.dir/src/init_threads.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/init_threads.c.o: ../src/init_threads.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/philo_one_cmake.dir/src/init_threads.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/init_threads.c.o   -c /home/boat/codam/philosophers/philo_one/src/init_threads.c

CMakeFiles/philo_one_cmake.dir/src/init_threads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/init_threads.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/init_threads.c > CMakeFiles/philo_one_cmake.dir/src/init_threads.c.i

CMakeFiles/philo_one_cmake.dir/src/init_threads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/init_threads.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/init_threads.c -o CMakeFiles/philo_one_cmake.dir/src/init_threads.c.s

CMakeFiles/philo_one_cmake.dir/src/main.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/philo_one_cmake.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/main.c.o   -c /home/boat/codam/philosophers/philo_one/src/main.c

CMakeFiles/philo_one_cmake.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/main.c > CMakeFiles/philo_one_cmake.dir/src/main.c.i

CMakeFiles/philo_one_cmake.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/main.c -o CMakeFiles/philo_one_cmake.dir/src/main.c.s

CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.o: ../src/not_atoi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.o   -c /home/boat/codam/philosophers/philo_one/src/not_atoi.c

CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/not_atoi.c > CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.i

CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/not_atoi.c -o CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.s

CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.o: ../src/not_bzero.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.o   -c /home/boat/codam/philosophers/philo_one/src/not_bzero.c

CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/not_bzero.c > CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.i

CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/not_bzero.c -o CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.s

CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.o: ../src/not_isdigit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.o   -c /home/boat/codam/philosophers/philo_one/src/not_isdigit.c

CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/not_isdigit.c > CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.i

CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/not_isdigit.c -o CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.s

CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.o: ../src/parse_arguments.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.o   -c /home/boat/codam/philosophers/philo_one/src/parse_arguments.c

CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/parse_arguments.c > CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.i

CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/parse_arguments.c -o CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.s

CMakeFiles/philo_one_cmake.dir/src/philosopher.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/philosopher.c.o: ../src/philosopher.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/philo_one_cmake.dir/src/philosopher.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/philosopher.c.o   -c /home/boat/codam/philosophers/philo_one/src/philosopher.c

CMakeFiles/philo_one_cmake.dir/src/philosopher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/philosopher.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/philosopher.c > CMakeFiles/philo_one_cmake.dir/src/philosopher.c.i

CMakeFiles/philo_one_cmake.dir/src/philosopher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/philosopher.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/philosopher.c -o CMakeFiles/philo_one_cmake.dir/src/philosopher.c.s

CMakeFiles/philo_one_cmake.dir/src/println.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/println.c.o: ../src/println.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/philo_one_cmake.dir/src/println.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/println.c.o   -c /home/boat/codam/philosophers/philo_one/src/println.c

CMakeFiles/philo_one_cmake.dir/src/println.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/println.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/println.c > CMakeFiles/philo_one_cmake.dir/src/println.c.i

CMakeFiles/philo_one_cmake.dir/src/println.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/println.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/println.c -o CMakeFiles/philo_one_cmake.dir/src/println.c.s

CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.o: ../src/puts_unlocked.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.o   -c /home/boat/codam/philosophers/philo_one/src/puts_unlocked.c

CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/puts_unlocked.c > CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.i

CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/puts_unlocked.c -o CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.s

CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.o: ../src/start_simulation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.o   -c /home/boat/codam/philosophers/philo_one/src/start_simulation.c

CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/start_simulation.c > CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.i

CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/start_simulation.c -o CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.s

CMakeFiles/philo_one_cmake.dir/src/take_fork.c.o: CMakeFiles/philo_one_cmake.dir/flags.make
CMakeFiles/philo_one_cmake.dir/src/take_fork.c.o: ../src/take_fork.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/philo_one_cmake.dir/src/take_fork.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one_cmake.dir/src/take_fork.c.o   -c /home/boat/codam/philosophers/philo_one/src/take_fork.c

CMakeFiles/philo_one_cmake.dir/src/take_fork.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one_cmake.dir/src/take_fork.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/boat/codam/philosophers/philo_one/src/take_fork.c > CMakeFiles/philo_one_cmake.dir/src/take_fork.c.i

CMakeFiles/philo_one_cmake.dir/src/take_fork.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one_cmake.dir/src/take_fork.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/boat/codam/philosophers/philo_one/src/take_fork.c -o CMakeFiles/philo_one_cmake.dir/src/take_fork.c.s

# Object files for target philo_one_cmake
philo_one_cmake_OBJECTS = \
"CMakeFiles/philo_one_cmake.dir/src/do_eat.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/gettime.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/init_threads.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/main.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/philosopher.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/println.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.o" \
"CMakeFiles/philo_one_cmake.dir/src/take_fork.c.o"

# External object files for target philo_one_cmake
philo_one_cmake_EXTERNAL_OBJECTS =

philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/do_eat.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/do_sleep.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/drop_forks.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/fake_trylock.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/gettime.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/hecking_die.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/init_mutex.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/init_threads.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/main.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/not_atoi.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/not_bzero.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/not_isdigit.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/parse_arguments.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/philosopher.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/println.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/puts_unlocked.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/start_simulation.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/src/take_fork.c.o
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/build.make
philo_one_cmake: CMakeFiles/philo_one_cmake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking C executable philo_one_cmake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo_one_cmake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo_one_cmake.dir/build: philo_one_cmake

.PHONY : CMakeFiles/philo_one_cmake.dir/build

CMakeFiles/philo_one_cmake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo_one_cmake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo_one_cmake.dir/clean

CMakeFiles/philo_one_cmake.dir/depend:
	cd /home/boat/codam/philosophers/philo_one/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/boat/codam/philosophers/philo_one /home/boat/codam/philosophers/philo_one /home/boat/codam/philosophers/philo_one/cmake-build-debug /home/boat/codam/philosophers/philo_one/cmake-build-debug /home/boat/codam/philosophers/philo_one/cmake-build-debug/CMakeFiles/philo_one_cmake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo_one_cmake.dir/depend
