cmake_minimum_required(VERSION 3.10)
project(mygame)

set(SOURCES
engine/src/glad.c
engine/src/main.c
)

set(LIBS
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2main.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL2.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/freetype.lib
)

include_directories(include)

add_executable(mygame ${SOURCES})

target_link_libraries(mygame ${LIBS})