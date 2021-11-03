cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(Leaf LANGUAGES CXX)
elseif(UNIX)
    project(Leaf)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6 COMPONENTS Sql REQUIRED)

#=================== INCLUSION OF Project Files ====================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(MODELS_DIR "${CMAKE_SOURCE_DIR}/include/Models")
set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/res")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${MODELS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${RESOURCES_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${RESOURCES_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${MODELS_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32)
    add_executable(Leaf WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(Leaf ${SOURCES})
endif()

# Add the target includes for MY_PROJECT
target_include_directories(Leaf PRIVATE ${FORMS_DIR})
target_include_directories(Leaf PRIVATE ${INCLUDE_DIR})
target_include_directories(Leaf PRIVATE ${RESOURCES_DIR})
target_include_directories(Leaf PRIVATE ${SOURCE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(Leaf Qt6::Widgets)
target_link_libraries(Leaf Qt6::Sql)

set_target_properties(Leaf PROPERTIES OUTPUT_NAME "Leaf")
