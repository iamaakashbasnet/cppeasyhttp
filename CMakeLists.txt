cmake_minimum_required(VERSION 3.0.0)
project(cppeasyhttp VERSION 0.1.0 LANGUAGES C CXX)


find_package(
    cpr REQUIRED
)

add_executable(
    main src/main.cpp
)

target_link_libraries(
    main cpr::cpr
)