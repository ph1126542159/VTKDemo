project(3dparty)

add_definitions(-DTHIRDPARTY_LIBRARY)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        include/3dparty_global.h
        include/flowlayout.h
        include/QRoundProgressBar.h
        src/flowlayout.cpp
        src/QRoundProgressBar.cpp
)
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)