cmake_minimum_required(VERSION 3.10)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(ProjectName "video-flow-control")
set(ProjectNamespace "VFC")

project("${ProjectName}")

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fdiagnostics-color=always -Wall -g")

include_directories(${PROJECT_SOURCE_DIR}/dependencies)
include_directories(${PROJECT_SOURCE_DIR}/dependencies/imgui)

# =========================================================
# gtest

include(FetchContent)
FetchContent_Declare(
    googletest
    URL
    https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set_property(TARGET gmock PROPERTY FOLDER "gtest")
set_property(TARGET gmock_main PROPERTY FOLDER "gtest")
set_property(TARGET gtest PROPERTY FOLDER "gtest")
set_property(TARGET gtest_main PROPERTY FOLDER "gtest")

# =========================================================

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library("${ProjectName}" STATIC
    # Source files
    src/information.cc
    dependencies/imgui/imgui.cpp
    dependencies/imgui/imgui_widgets.cpp
    dependencies/imgui/imgui_tables.cpp
    dependencies/imgui/imgui_impl_opengl3.cpp
    dependencies/imgui/imgui_impl_glfw.cpp
    dependencies/imgui/imgui_draw.cpp
    dependencies/imgui/imgui_demo.cpp
    
    # Header files
    include/information.h
)

target_compile_definitions("${ProjectName}" PRIVATE PROJECT_NAMESPACE=${ProjectNamespace})

add_executable("${ProjectName}-main"
    # Source files
    src/driver.cc

    # Header files
)

find_library(OPENGL_LIBRARY OpenGL)
find_library(COCOA_LIBRARY Cocoa)
find_library(IOKIT_LIBRARY IOKit)
find_library(COREVIDEO_LIBRARY CoreVideo)
find_library(COREFOUNDATION_LIBRARY CoreFoundation)

target_link_libraries("${ProjectName}-main" 
    ${OPENGL_LIBRARY} 
    ${COCOA_LIBRARY} 
    ${IOKIT_LIBRARY} 
    ${COREVIDEO_LIBRARY} 
    ${COREFOUNDATION_LIBRARY}
)

target_link_libraries("${ProjectName}-main" 
    "${ProjectName}"
    glfw
)

# gtest

enable_testing()

add_executable("${ProjectName}-test"
    # Source files
    test/sanity_test.cpp

    # Head files
)

target_link_libraries("${ProjectName}-test"
    gtest_main
    "${ProjectName}"
)

include(GoogleTest)
gtest_discover_tests("${ProjectName}-test")