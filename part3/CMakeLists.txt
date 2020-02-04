cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(tutorial VERSION 0.0.1 LANGUAGES CXX)

add_executable(tutorial
	main.cpp
)

# MarlinMulticastSDK
include("${CMAKE_CURRENT_LIST_DIR}/cmake/marlin-multicastsdk.cmake")
target_link_libraries(tutorial PUBLIC marlin::multicastsdk)
