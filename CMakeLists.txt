cmake_minimum_required(VERSION 3.20)
project(opengl-freeglut C)

set(FREEGLUT_THIRD_PARTY_DIR third_party/freeglut-3.4.0)

option(FREEGLUT_BUILD_DEMOS "Freeglut build demos" OFF)
set(OpenGL_GL_PREFERENCE LEGACY)
add_subdirectory(${FREEGLUT_THIRD_PARTY_DIR})

include_directories(include)

set(SOURCE_FILES main.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${FREEGLUT_THIRD_PARTY_DIR}/include)
target_link_libraries(${PROJECT_NAME} freeglut GLU)

add_subdirectory(examples)
add_subdirectory(transform2d)
