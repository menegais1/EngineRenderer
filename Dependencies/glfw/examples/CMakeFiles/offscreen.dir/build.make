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
include Dependencies/glfw/examples/CMakeFiles/offscreen.dir/depend.make

# Include the progress variables for this target.
include Dependencies/glfw/examples/CMakeFiles/offscreen.dir/progress.make

# Include the compile flags for this target's objects.
include Dependencies/glfw/examples/CMakeFiles/offscreen.dir/flags.make

Dependencies/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.o: Dependencies/glfw/examples/CMakeFiles/offscreen.dir/flags.make
Dependencies/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.o: Dependencies/glfw/examples/offscreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Dependencies/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.o"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/offscreen.dir/offscreen.c.o   -c /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples/offscreen.c

Dependencies/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/offscreen.c.i"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples/offscreen.c > CMakeFiles/offscreen.dir/offscreen.c.i

Dependencies/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/offscreen.c.s"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples/offscreen.c -o CMakeFiles/offscreen.dir/offscreen.c.s

Dependencies/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: Dependencies/glfw/examples/CMakeFiles/offscreen.dir/flags.make
Dependencies/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: Dependencies/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Dependencies/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o   -c /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/deps/glad_gl.c

Dependencies/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/deps/glad_gl.c > CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i

Dependencies/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/deps/glad_gl.c -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s

# Object files for target offscreen
offscreen_OBJECTS = \
"CMakeFiles/offscreen.dir/offscreen.c.o" \
"CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"

# External object files for target offscreen
offscreen_EXTERNAL_OBJECTS =

Dependencies/glfw/examples/offscreen: Dependencies/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.o
Dependencies/glfw/examples/offscreen: Dependencies/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o
Dependencies/glfw/examples/offscreen: Dependencies/glfw/examples/CMakeFiles/offscreen.dir/build.make
Dependencies/glfw/examples/offscreen: Dependencies/glfw/src/libglfw3.a
Dependencies/glfw/examples/offscreen: /usr/lib/x86_64-linux-gnu/libm.so
Dependencies/glfw/examples/offscreen: /usr/lib/x86_64-linux-gnu/librt.so
Dependencies/glfw/examples/offscreen: /usr/lib/x86_64-linux-gnu/libm.so
Dependencies/glfw/examples/offscreen: /usr/lib/x86_64-linux-gnu/libX11.so
Dependencies/glfw/examples/offscreen: Dependencies/glfw/examples/CMakeFiles/offscreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable offscreen"
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/offscreen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Dependencies/glfw/examples/CMakeFiles/offscreen.dir/build: Dependencies/glfw/examples/offscreen

.PHONY : Dependencies/glfw/examples/CMakeFiles/offscreen.dir/build

Dependencies/glfw/examples/CMakeFiles/offscreen.dir/clean:
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/offscreen.dir/cmake_clean.cmake
.PHONY : Dependencies/glfw/examples/CMakeFiles/offscreen.dir/clean

Dependencies/glfw/examples/CMakeFiles/offscreen.dir/depend:
	cd /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples /home/menegais1/Documents/Projects/ComputerGraphics/Study/EngineRenderer/Dependencies/glfw/examples/CMakeFiles/offscreen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Dependencies/glfw/examples/CMakeFiles/offscreen.dir/depend

