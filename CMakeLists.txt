cmake_minimum_required(VERSION 3.0)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(smail CXX)
find_package(Qt5Widgets)
find_package(Threads)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_compile_options(-Wall -Werror)

include(FindCXX11)

add_library(ui
    chancevariable.cpp
    mainwindow.cpp
    )
target_link_libraries(ui Qt5::Widgets)

set(smail_SRC
    generator.cpp
    main.cpp
    random.cpp
    reception.cpp
    system.cpp
    )
add_executable(smail ${smail_SRC})
target_link_libraries(smail ui ${CMAKE_THREAD_LIBS_INIT})
