project(custom3dwidget)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

FILE(GLOB SRC_FILES "./*.cpp") 
FILE(GLOB HEADER_FILES "./*.h") 
FILE(GLOB UI_FILES "./*.ui") 


set(PROJECT_SOURCES
    ${SRC_FILES} 
    ${HEADER_FILES} 
    ${UI_FILES}
)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include 
${CMAKE_CURRENT_SOURCE_DIR}/../../utils/include
${CMAKE_CURRENT_SOURCE_DIR}/../../widgets/include
${CMAKE_CURRENT_SOURCE_DIR}/../../vtkcore/include
)
target_link_libraries(${PROJECT_NAME} PRIVATE 
utils 
widgets 
vtkcore 
Qt${QT_VERSION_MAJOR}::Widgets 
${VTK_LIBRARIES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/plugins/"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/plugins/"
)