cmake_minimum_required(VERSION 3.20)
project(OrderBook)

set(CMAKE_CXX_STANDARD 20)

add_executable(OrderBook
    src/main.cpp
    src/OrderBook.cpp
)

target_include_directories(OrderBook PRIVATE src)