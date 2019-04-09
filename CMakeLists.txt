cmake_minimum_required(VERSION 3.6)
project(image)

add_definitions(-D _HAS_CXX17=1)
add_definitions(-D _HAS_CXX20=1)
add_definitions(-D _WIN32_WINNT=0x0601)
add_definitions(-D _MSC_VER=1920)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)

include_directories(src)

set(SOURCE
    src/Image.cpp
    src/Interface.cpp)

add_library(image SHARED ${SOURCE})
target_compile_features(image PRIVATE cxx_std_17)
target_compile_options(image PRIVATE /bigobj)
target_include_directories(image PRIVATE c:/opencv/include)
target_link_libraries(image c:/opencv/lib/opencv_core401d.lib)
target_link_libraries(image c:/opencv/lib/opencv_highgui401d.lib)
target_link_libraries(image c:/opencv/lib/opencv_imgproc401d.lib)
target_link_libraries(image c:/opencv/lib/opencv_videoio401d.lib)
target_link_libraries(image c:/opencv/lib/opencv_imgcodecs401d.lib)