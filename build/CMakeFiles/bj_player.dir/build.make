# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/Desktop/CSE3310/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Desktop/CSE3310/Project/build

# Include any dependencies generated for this target.
include CMakeFiles/bj_player.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bj_player.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bj_player.dir/flags.make

CMakeFiles/bj_player.dir/src/lobby_view.cpp.o: CMakeFiles/bj_player.dir/flags.make
CMakeFiles/bj_player.dir/src/lobby_view.cpp.o: ../src/lobby_view.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/CSE3310/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bj_player.dir/src/lobby_view.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bj_player.dir/src/lobby_view.cpp.o -c /home/student/Desktop/CSE3310/Project/src/lobby_view.cpp

CMakeFiles/bj_player.dir/src/lobby_view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bj_player.dir/src/lobby_view.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/CSE3310/Project/src/lobby_view.cpp > CMakeFiles/bj_player.dir/src/lobby_view.cpp.i

CMakeFiles/bj_player.dir/src/lobby_view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bj_player.dir/src/lobby_view.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/CSE3310/Project/src/lobby_view.cpp -o CMakeFiles/bj_player.dir/src/lobby_view.cpp.s

CMakeFiles/bj_player.dir/src/lobby_view.cpp.o.requires:

.PHONY : CMakeFiles/bj_player.dir/src/lobby_view.cpp.o.requires

CMakeFiles/bj_player.dir/src/lobby_view.cpp.o.provides: CMakeFiles/bj_player.dir/src/lobby_view.cpp.o.requires
	$(MAKE) -f CMakeFiles/bj_player.dir/build.make CMakeFiles/bj_player.dir/src/lobby_view.cpp.o.provides.build
.PHONY : CMakeFiles/bj_player.dir/src/lobby_view.cpp.o.provides

CMakeFiles/bj_player.dir/src/lobby_view.cpp.o.provides.build: CMakeFiles/bj_player.dir/src/lobby_view.cpp.o


CMakeFiles/bj_player.dir/src/main.cpp.o: CMakeFiles/bj_player.dir/flags.make
CMakeFiles/bj_player.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/CSE3310/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bj_player.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bj_player.dir/src/main.cpp.o -c /home/student/Desktop/CSE3310/Project/src/main.cpp

CMakeFiles/bj_player.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bj_player.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/CSE3310/Project/src/main.cpp > CMakeFiles/bj_player.dir/src/main.cpp.i

CMakeFiles/bj_player.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bj_player.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/CSE3310/Project/src/main.cpp -o CMakeFiles/bj_player.dir/src/main.cpp.s

CMakeFiles/bj_player.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/bj_player.dir/src/main.cpp.o.requires

CMakeFiles/bj_player.dir/src/main.cpp.o.provides: CMakeFiles/bj_player.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/bj_player.dir/build.make CMakeFiles/bj_player.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/bj_player.dir/src/main.cpp.o.provides

CMakeFiles/bj_player.dir/src/main.cpp.o.provides.build: CMakeFiles/bj_player.dir/src/main.cpp.o


CMakeFiles/bj_player.dir/src/login_view.cpp.o: CMakeFiles/bj_player.dir/flags.make
CMakeFiles/bj_player.dir/src/login_view.cpp.o: ../src/login_view.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/CSE3310/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bj_player.dir/src/login_view.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bj_player.dir/src/login_view.cpp.o -c /home/student/Desktop/CSE3310/Project/src/login_view.cpp

CMakeFiles/bj_player.dir/src/login_view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bj_player.dir/src/login_view.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/Desktop/CSE3310/Project/src/login_view.cpp > CMakeFiles/bj_player.dir/src/login_view.cpp.i

CMakeFiles/bj_player.dir/src/login_view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bj_player.dir/src/login_view.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/Desktop/CSE3310/Project/src/login_view.cpp -o CMakeFiles/bj_player.dir/src/login_view.cpp.s

CMakeFiles/bj_player.dir/src/login_view.cpp.o.requires:

.PHONY : CMakeFiles/bj_player.dir/src/login_view.cpp.o.requires

CMakeFiles/bj_player.dir/src/login_view.cpp.o.provides: CMakeFiles/bj_player.dir/src/login_view.cpp.o.requires
	$(MAKE) -f CMakeFiles/bj_player.dir/build.make CMakeFiles/bj_player.dir/src/login_view.cpp.o.provides.build
.PHONY : CMakeFiles/bj_player.dir/src/login_view.cpp.o.provides

CMakeFiles/bj_player.dir/src/login_view.cpp.o.provides.build: CMakeFiles/bj_player.dir/src/login_view.cpp.o


# Object files for target bj_player
bj_player_OBJECTS = \
"CMakeFiles/bj_player.dir/src/lobby_view.cpp.o" \
"CMakeFiles/bj_player.dir/src/main.cpp.o" \
"CMakeFiles/bj_player.dir/src/login_view.cpp.o"

# External object files for target bj_player
bj_player_EXTERNAL_OBJECTS =

bj_player: CMakeFiles/bj_player.dir/src/lobby_view.cpp.o
bj_player: CMakeFiles/bj_player.dir/src/main.cpp.o
bj_player: CMakeFiles/bj_player.dir/src/login_view.cpp.o
bj_player: CMakeFiles/bj_player.dir/build.make
bj_player: /usr/lib/x86_64-linux-gnu/libfltk_images.so
bj_player: /usr/lib/x86_64-linux-gnu/libfltk_forms.so
bj_player: /usr/lib/x86_64-linux-gnu/libfltk_gl.so
bj_player: /usr/lib/x86_64-linux-gnu/libGL.so
bj_player: /usr/lib/x86_64-linux-gnu/libfltk.so
bj_player: /usr/lib/x86_64-linux-gnu/libSM.so
bj_player: /usr/lib/x86_64-linux-gnu/libICE.so
bj_player: /usr/lib/x86_64-linux-gnu/libX11.so
bj_player: /usr/lib/x86_64-linux-gnu/libXext.so
bj_player: /usr/lib/x86_64-linux-gnu/libm.so
bj_player: CMakeFiles/bj_player.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/Desktop/CSE3310/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bj_player"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bj_player.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bj_player.dir/build: bj_player

.PHONY : CMakeFiles/bj_player.dir/build

CMakeFiles/bj_player.dir/requires: CMakeFiles/bj_player.dir/src/lobby_view.cpp.o.requires
CMakeFiles/bj_player.dir/requires: CMakeFiles/bj_player.dir/src/main.cpp.o.requires
CMakeFiles/bj_player.dir/requires: CMakeFiles/bj_player.dir/src/login_view.cpp.o.requires

.PHONY : CMakeFiles/bj_player.dir/requires

CMakeFiles/bj_player.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bj_player.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bj_player.dir/clean

CMakeFiles/bj_player.dir/depend:
	cd /home/student/Desktop/CSE3310/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Desktop/CSE3310/Project /home/student/Desktop/CSE3310/Project /home/student/Desktop/CSE3310/Project/build /home/student/Desktop/CSE3310/Project/build /home/student/Desktop/CSE3310/Project/build/CMakeFiles/bj_player.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bj_player.dir/depend

