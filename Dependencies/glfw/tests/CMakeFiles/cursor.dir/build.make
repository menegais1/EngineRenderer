# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer

# Include any dependencies generated for this target.
include Dependencies/glfw/tests/CMakeFiles/cursor.dir/depend.make

# Include the progress variables for this target.
include Dependencies/glfw/tests/CMakeFiles/cursor.dir/progress.make

# Include the compile flags for this target's objects.
include Dependencies/glfw/tests/CMakeFiles/cursor.dir/flags.make

Dependencies/glfw/tests/CMakeFiles/cursor.dir/cursor.c.o: Dependencies/glfw/tests/CMakeFiles/cursor.dir/flags.make
Dependencies/glfw/tests/CMakeFiles/cursor.dir/cursor.c.o: Dependencies/glfw/tests/cursor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Dependencies/glfw/tests/CMakeFiles/cursor.dir/cursor.c.o"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cursor.dir/cursor.c.o   -c /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests/cursor.c

Dependencies/glfw/tests/CMakeFiles/cursor.dir/cursor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cursor.dir/cursor.c.i"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests/cursor.c > CMakeFiles/cursor.dir/cursor.c.i

Dependencies/glfw/tests/CMakeFiles/cursor.dir/cursor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cursor.dir/cursor.c.s"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests/cursor.c -o CMakeFiles/cursor.dir/cursor.c.s

Dependencies/glfw/tests/CMakeFiles/cursor.dir/__/deps/glad_gl.c.o: Dependencies/glfw/tests/CMakeFiles/cursor.dir/flags.make
Dependencies/glfw/tests/CMakeFiles/cursor.dir/__/deps/glad_gl.c.o: Dependencies/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Dependencies/glfw/tests/CMakeFiles/cursor.dir/__/deps/glad_gl.c.o"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cursor.dir/__/deps/glad_gl.c.o   -c /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/deps/glad_gl.c

Dependencies/glfw/tests/CMakeFiles/cursor.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cursor.dir/__/deps/glad_gl.c.i"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/deps/glad_gl.c > CMakeFiles/cursor.dir/__/deps/glad_gl.c.i

Dependencies/glfw/tests/CMakeFiles/cursor.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cursor.dir/__/deps/glad_gl.c.s"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/deps/glad_gl.c -o CMakeFiles/cursor.dir/__/deps/glad_gl.c.s

# Object files for target cursor
cursor_OBJECTS = \
"CMakeFiles/cursor.dir/cursor.c.o" \
"CMakeFiles/cursor.dir/__/deps/glad_gl.c.o"

# External object files for target cursor
cursor_EXTERNAL_OBJECTS =

Dependencies/glfw/tests/cursor: Dependencies/glfw/tests/CMakeFiles/cursor.dir/cursor.c.o
Dependencies/glfw/tests/cursor: Dependencies/glfw/tests/CMakeFiles/cursor.dir/__/deps/glad_gl.c.o
Dependencies/glfw/tests/cursor: Dependencies/glfw/tests/CMakeFiles/cursor.dir/build.make
Dependencies/glfw/tests/cursor: Dependencies/glfw/src/libglfw3.a
Dependencies/glfw/tests/cursor: /usr/lib/x86_64-linux-gnu/libm.so
Dependencies/glfw/tests/cursor: /usr/lib/x86_64-linux-gnu/librt.so
Dependencies/glfw/tests/cursor: /usr/lib/x86_64-linux-gnu/libm.so
Dependencies/glfw/tests/cursor: /usr/lib/x86_64-linux-gnu/libX11.so
Dependencies/glfw/tests/cursor: Dependencies/glfw/tests/CMakeFiles/cursor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable cursor"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cursor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Dependencies/glfw/tests/CMakeFiles/cursor.dir/build: Dependencies/glfw/tests/cursor

.PHONY : Dependencies/glfw/tests/CMakeFiles/cursor.dir/build

Dependencies/glfw/tests/CMakeFiles/cursor.dir/clean:
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests && $(CMAKE_COMMAND) -P CMakeFiles/cursor.dir/cmake_clean.cmake
.PHONY : Dependencies/glfw/tests/CMakeFiles/cursor.dir/clean

Dependencies/glfw/tests/CMakeFiles/cursor.dir/depend:
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/tests/CMakeFiles/cursor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Dependencies/glfw/tests/CMakeFiles/cursor.dir/depend

