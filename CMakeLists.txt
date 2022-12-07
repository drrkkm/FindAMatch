cmake_minimum_required(VERSION 3.5)

project(checkers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(FLTK_SKIP_FLUID True)
set(OpenGL_GL_PREFERENCE "GLVND")

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)


set(GRAPHLIB_DIR "../../../lib")

include_directories(
    ${GRAPHLIB_DIR}
    SYSTEM
    ${FLTK_INCLUDE_DIR}
)

add_executable(
    checkers
    ${GRAPHLIB_DIR}/Graph_lib/Graph.cpp
    ${GRAPHLIB_DIR}/Graph_lib/Graph.h
    ${GRAPHLIB_DIR}/Graph_lib/GUI.cpp
    ${GRAPHLIB_DIR}/Graph_lib/GUI.h
    ${GRAPHLIB_DIR}/Graph_lib/Window.cpp
    ${GRAPHLIB_DIR}/Graph_lib/Window.h
    board.cpp
    board.h
    cell.cpp
    cell.h
    checkers.cpp
    checkers.h
    utils.h
    main.cpp
)

target_link_libraries(
    checkers
    ${FLTK_LIBRARIES}
    ${OPENGL_LIBRARIES}
)

install(TARGETS checkers)
