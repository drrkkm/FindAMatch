cmake_minimum_required(VERSION 3.5)

project(checkers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(FLTK_SKIP_FLUID True)
set(OpenGL_GL_PREFERENCE "GLVND")

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)


set(GRAPHLIB_DIR ".")

include_directories(
    ${GRAPHLIB_DIR}
    SYSTEM
    ${FLTK_INCLUDE_DIR}
)

link_directories(
    ${FLTK_INCLUDE_DIR}/../lib
)

add_executable(
    checkers
    ${GRAPHLIB_DIR}/Graph_lib/Graph.cpp
    ${GRAPHLIB_DIR}/Graph_lib/Graph.h
    ${GRAPHLIB_DIR}/Graph_lib/GUI.cpp
    ${GRAPHLIB_DIR}/Graph_lib/GUI.h
    ${GRAPHLIB_DIR}/Graph_lib/Window.cpp
    ${GRAPHLIB_DIR}/Graph_lib/Window.h
    ${GRAPHLIB_DIR}/Graph_lib/Regular_hexagon.cpp
    ${GRAPHLIB_DIR}/Graph_lib/Regular_hexagon.h
    board.cpp
    board.h
    cell.cpp
    cell.h
    game.cpp
    game.h
    utils.h
    main.cpp
    pictures.h
)

target_link_libraries(
    checkers
    ${FLTK_LIBRARIES}
    fltk_png
    fltk_z
    fltk_jpeg
    ${OPENGL_LIBRARIES}
)

install(TARGETS checkers)
