# CMake Version
cmake_minimum_required(VERSION 3.3)

# Constants
set(PROJECT_NAME "desistir")
set(OpenGL_GL_PREFERENCE LEGACY)

# Project Name
project(${PROJECT_NAME})

# Packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# File Globs
file(GLOB SOURCES_FILES src/Sources/*.c)
file(GLOB HEADERS_FILES src/Headers/*.h)

# Executable
add_executable(
  ${PROJECT_NAME}
  src/Main.c
  ${SOURCES_FILES}
  ${HEADERS_FILES}
)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} PUBLIC GL GLEW glfw)
