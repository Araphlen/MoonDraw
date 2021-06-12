cmake_minimum_required(VERSION 3.10)

project(moonDraw VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# add the executable
add_executable(main controler/main.cpp vue/MyControlPanel.cpp vue/headers/MyControlPanel.h vue/MyApp.cpp vue/headers/MyApp.h vue/MyFrame.cpp vue/headers/MyFrame.h vue/MyDrawingPanel.cpp vue/headers/MyDrawingPanel.h model/Rectangle.cpp model/headers/Rectangle.h model/Figure.cpp model/headers/Figure.h model/Drawing.cpp model/headers/Drawing.h model/Point.cpp model/headers/Point.h model/Circle.cpp model/headers/Circle.h model/Ellipse.cpp model/headers/Ellipse.h model/Polygon.cpp model/headers/Polygon.h model/MyRgb.cpp model/headers/MyRgb.h vue/headers/MyInfoPanel.h)
target_link_libraries(main ${wxWidgets_LIBRARIES})
