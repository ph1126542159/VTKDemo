cmake_minimum_required(VERSION 3.5)
project(VTKDemo)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_EXPO)
set(CMAKE_CXX_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(WIN32)
    add_compile_options(/W4)
    add_compile_options(/wd4819)
endif()

set(CMAKE_BUILD_TYPE "Debug" )


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


find_package(VTK REQUIRED)

if (NOT VTK_FOUND)
  message("Skipping example: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif ()


add_subdirectory(3dparty)
add_subdirectory(widgets)
add_subdirectory(utils)
add_subdirectory(vtkcore)
add_subdirectory(plugins)
add_subdirectory(App)


