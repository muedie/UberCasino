cmake_minimum_required (VERSION 3.2)

project (BLACKJACK)

find_package(FLTK REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable (bj_player ${SOURCES})

target_link_libraries (bj_player ${FLTK_LIBRARIES})
