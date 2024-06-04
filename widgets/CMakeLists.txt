project(widgets)

add_definitions(-DWIDGETS_LIBRARY)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB HEASER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
aux_source_directory(src SRC)
set(PROJECT_SOURCES
        ${HEASER_FILES}
        ${SRC}
)
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include 
${CMAKE_CURRENT_SOURCE_DIR}/../3dparty/include
)
target_link_libraries(${PROJECT_NAME} PRIVATE 3dparty Qt${QT_VERSION_MAJOR}::Widgets)