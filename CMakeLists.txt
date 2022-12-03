cmake_minimum_required(VERSION 3.22)
set( CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" )

project(MotherInLaw)

find_package(OpenCV CONFIG REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(MotherInLaw main.cpp import.cpp export.cpp)
target_link_libraries(MotherInLaw ${OpenCV_LIBS})
