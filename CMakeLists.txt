cmake_minimum_required(VERSION 2.8)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(smail CXX)

list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_compile_options(-Wall -Werror)

include(FindCXX11)

set(smail_SRC
    main.cpp
    reception.cpp
    )
add_executable(smail ${smail_SRC})
