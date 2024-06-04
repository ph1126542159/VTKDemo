project(animation)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        animationplugin.h
        animationscenewindow.h
        basicanimationwindow.h
        animationplugin.cpp
        animationscenewindow.cpp
        basicanimationwindow.cpp
        animationscenewindow.ui
        basicanimationwindow.ui
)

SET(RCC_FILES img.qrc)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES} ${RCC_FILES})


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include 
${CMAKE_CURRENT_SOURCE_DIR}/../../utils/include
${CMAKE_CURRENT_SOURCE_DIR}/../../vtkcore/include
)
target_link_libraries(${PROJECT_NAME} PRIVATE utils vtkcore Qt${QT_VERSION_MAJOR}::Widgets ${VTK_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/plugins/"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/plugins/"
)
