cmake_minimum_required(VERSION 3.10)

project(moonDraw VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
add_executable(main main.cpp vue/MyControlPanel.cpp vue/headers/MyControlPanel.h vue/MyApp.cpp vue/headers/MyApp.h vue/MyFrame.cpp vue/headers/MyFrame.h vue/MyDrawingPanel.cpp vue/headers/MyDrawingPanel.h model/Rectangle.cpp model/Rectangle.h model/Figure.cpp model/Figure.h model/Dessin.cpp model/Dessin.h)
target_link_libraries(main ${wxWidgets_LIBRARIES})
