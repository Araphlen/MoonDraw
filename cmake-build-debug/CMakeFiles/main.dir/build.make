# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2020.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.3.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/araphlen/CLionProjects/MoonDraw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/araphlen/CLionProjects/MoonDraw/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/vue/MyControlPanel.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/vue/MyControlPanel.cpp.o: ../vue/MyControlPanel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/vue/MyControlPanel.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/vue/MyControlPanel.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/vue/MyControlPanel.cpp

CMakeFiles/main.dir/vue/MyControlPanel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/vue/MyControlPanel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/vue/MyControlPanel.cpp > CMakeFiles/main.dir/vue/MyControlPanel.cpp.i

CMakeFiles/main.dir/vue/MyControlPanel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/vue/MyControlPanel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/vue/MyControlPanel.cpp -o CMakeFiles/main.dir/vue/MyControlPanel.cpp.s

CMakeFiles/main.dir/vue/MyApp.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/vue/MyApp.cpp.o: ../vue/MyApp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/vue/MyApp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/vue/MyApp.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/vue/MyApp.cpp

CMakeFiles/main.dir/vue/MyApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/vue/MyApp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/vue/MyApp.cpp > CMakeFiles/main.dir/vue/MyApp.cpp.i

CMakeFiles/main.dir/vue/MyApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/vue/MyApp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/vue/MyApp.cpp -o CMakeFiles/main.dir/vue/MyApp.cpp.s

CMakeFiles/main.dir/vue/MyFrame.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/vue/MyFrame.cpp.o: ../vue/MyFrame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/vue/MyFrame.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/vue/MyFrame.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/vue/MyFrame.cpp

CMakeFiles/main.dir/vue/MyFrame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/vue/MyFrame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/vue/MyFrame.cpp > CMakeFiles/main.dir/vue/MyFrame.cpp.i

CMakeFiles/main.dir/vue/MyFrame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/vue/MyFrame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/vue/MyFrame.cpp -o CMakeFiles/main.dir/vue/MyFrame.cpp.s

CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.o: ../vue/MyDrawingPanel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/vue/MyDrawingPanel.cpp

CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/vue/MyDrawingPanel.cpp > CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.i

CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/vue/MyDrawingPanel.cpp -o CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.s

CMakeFiles/main.dir/model/Rectangle.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/model/Rectangle.cpp.o: ../model/Rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/model/Rectangle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/model/Rectangle.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/model/Rectangle.cpp

CMakeFiles/main.dir/model/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/model/Rectangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/model/Rectangle.cpp > CMakeFiles/main.dir/model/Rectangle.cpp.i

CMakeFiles/main.dir/model/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/model/Rectangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/model/Rectangle.cpp -o CMakeFiles/main.dir/model/Rectangle.cpp.s

CMakeFiles/main.dir/model/Figure.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/model/Figure.cpp.o: ../model/Figure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/model/Figure.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/model/Figure.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/model/Figure.cpp

CMakeFiles/main.dir/model/Figure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/model/Figure.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/model/Figure.cpp > CMakeFiles/main.dir/model/Figure.cpp.i

CMakeFiles/main.dir/model/Figure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/model/Figure.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/model/Figure.cpp -o CMakeFiles/main.dir/model/Figure.cpp.s

CMakeFiles/main.dir/model/Drawing.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/model/Drawing.cpp.o: ../model/Drawing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/model/Drawing.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/model/Drawing.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/model/Drawing.cpp

CMakeFiles/main.dir/model/Drawing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/model/Drawing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/model/Drawing.cpp > CMakeFiles/main.dir/model/Drawing.cpp.i

CMakeFiles/main.dir/model/Drawing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/model/Drawing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/model/Drawing.cpp -o CMakeFiles/main.dir/model/Drawing.cpp.s

CMakeFiles/main.dir/model/Point.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/model/Point.cpp.o: ../model/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/model/Point.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/model/Point.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/model/Point.cpp

CMakeFiles/main.dir/model/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/model/Point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/model/Point.cpp > CMakeFiles/main.dir/model/Point.cpp.i

CMakeFiles/main.dir/model/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/model/Point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/model/Point.cpp -o CMakeFiles/main.dir/model/Point.cpp.s

CMakeFiles/main.dir/model/Circle.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/model/Circle.cpp.o: ../model/Circle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/main.dir/model/Circle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/model/Circle.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/model/Circle.cpp

CMakeFiles/main.dir/model/Circle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/model/Circle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/model/Circle.cpp > CMakeFiles/main.dir/model/Circle.cpp.i

CMakeFiles/main.dir/model/Circle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/model/Circle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/model/Circle.cpp -o CMakeFiles/main.dir/model/Circle.cpp.s

CMakeFiles/main.dir/model/Ellipse.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/model/Ellipse.cpp.o: ../model/Ellipse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/main.dir/model/Ellipse.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/model/Ellipse.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/model/Ellipse.cpp

CMakeFiles/main.dir/model/Ellipse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/model/Ellipse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/model/Ellipse.cpp > CMakeFiles/main.dir/model/Ellipse.cpp.i

CMakeFiles/main.dir/model/Ellipse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/model/Ellipse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/model/Ellipse.cpp -o CMakeFiles/main.dir/model/Ellipse.cpp.s

CMakeFiles/main.dir/model/Polygon.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/model/Polygon.cpp.o: ../model/Polygon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/main.dir/model/Polygon.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/model/Polygon.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/model/Polygon.cpp

CMakeFiles/main.dir/model/Polygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/model/Polygon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/model/Polygon.cpp > CMakeFiles/main.dir/model/Polygon.cpp.i

CMakeFiles/main.dir/model/Polygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/model/Polygon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/model/Polygon.cpp -o CMakeFiles/main.dir/model/Polygon.cpp.s

CMakeFiles/main.dir/model/MyRgb.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/model/MyRgb.cpp.o: ../model/MyRgb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/main.dir/model/MyRgb.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/model/MyRgb.cpp.o -c /home/araphlen/CLionProjects/MoonDraw/model/MyRgb.cpp

CMakeFiles/main.dir/model/MyRgb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/model/MyRgb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/araphlen/CLionProjects/MoonDraw/model/MyRgb.cpp > CMakeFiles/main.dir/model/MyRgb.cpp.i

CMakeFiles/main.dir/model/MyRgb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/model/MyRgb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/araphlen/CLionProjects/MoonDraw/model/MyRgb.cpp -o CMakeFiles/main.dir/model/MyRgb.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/vue/MyControlPanel.cpp.o" \
"CMakeFiles/main.dir/vue/MyApp.cpp.o" \
"CMakeFiles/main.dir/vue/MyFrame.cpp.o" \
"CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.o" \
"CMakeFiles/main.dir/model/Rectangle.cpp.o" \
"CMakeFiles/main.dir/model/Figure.cpp.o" \
"CMakeFiles/main.dir/model/Drawing.cpp.o" \
"CMakeFiles/main.dir/model/Point.cpp.o" \
"CMakeFiles/main.dir/model/Circle.cpp.o" \
"CMakeFiles/main.dir/model/Ellipse.cpp.o" \
"CMakeFiles/main.dir/model/Polygon.cpp.o" \
"CMakeFiles/main.dir/model/MyRgb.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/vue/MyControlPanel.cpp.o
main: CMakeFiles/main.dir/vue/MyApp.cpp.o
main: CMakeFiles/main.dir/vue/MyFrame.cpp.o
main: CMakeFiles/main.dir/vue/MyDrawingPanel.cpp.o
main: CMakeFiles/main.dir/model/Rectangle.cpp.o
main: CMakeFiles/main.dir/model/Figure.cpp.o
main: CMakeFiles/main.dir/model/Drawing.cpp.o
main: CMakeFiles/main.dir/model/Point.cpp.o
main: CMakeFiles/main.dir/model/Circle.cpp.o
main: CMakeFiles/main.dir/model/Ellipse.cpp.o
main: CMakeFiles/main.dir/model/Polygon.cpp.o
main: CMakeFiles/main.dir/model/MyRgb.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/local/lib/libwx_baseu_net-3.0.a
main: /usr/local/lib/libwx_gtk3u_core-3.0.a
main: /usr/local/lib/libwx_baseu-3.0.a
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/araphlen/CLionProjects/MoonDraw/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/araphlen/CLionProjects/MoonDraw /home/araphlen/CLionProjects/MoonDraw /home/araphlen/CLionProjects/MoonDraw/cmake-build-debug /home/araphlen/CLionProjects/MoonDraw/cmake-build-debug /home/araphlen/CLionProjects/MoonDraw/cmake-build-debug/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

