cmake_minimum_required(VERSION 3.16)

project(sweet-crush-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sweet-crush-game main.cpp
    board.h
    board.cpp
    view.h
    view.cpp)

include(GNUInstallDirs)
install(TARGETS sweet-crush-game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
