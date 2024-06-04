project(App)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


file(GLOB HEASER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
aux_source_directory(src SRC)

set(PROJECT_SOURCES
        ${HEASER_FILES}
        ${SRC}
)
add_executable(${PROJECT_NAME}  ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE 
${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_CURRENT_SOURCE_DIR}/../utils/include
${CMAKE_CURRENT_SOURCE_DIR}/../widgets/include
${CMAKE_CURRENT_SOURCE_DIR}/../vtkcore/include
)
target_link_libraries(${PROJECT_NAME} PRIVATE 3dparty widgets vtkcore Qt${QT_VERSION_MAJOR}::Widgets)