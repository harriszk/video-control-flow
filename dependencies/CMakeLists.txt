#add_subdirectory(submodules)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}/dependencies/glfw
    ${PROJECT_SOURCE_DIR}/dependencies/khr
    ${PROJECT_SOURCE_DIR}/dependencies/glad
    ${PROJECT_SOURCE_DIR}/dependencies/glm
    ${PROJECT_SOURCE_DIR}/dependencies/imgui
)