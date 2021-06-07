cmake_minimum_required(VERSION 3.10)

project(skeleton VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
add_executable(main main.cpp model/MyControlPanel.cpp model/headers/MyControlPanel.h model/MyApp.cpp model/headers/MyApp.h model/MyFrame.cpp model/headers/MyFrame.h model/headers/contantes.h model/headers/enum.h model/MyDrawingPanel.cpp model/headers/MyDrawingPanel.h)
target_link_libraries(main ${wxWidgets_LIBRARIES})
