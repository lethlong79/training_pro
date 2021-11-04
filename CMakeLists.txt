cmake_minimum_required(VERSION 3.21.3)

# set the project name
project(Training_Project)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set include directory
include_directories(include)

# add the executable
add_executable(client 
	src/Client.cpp
	src/SocDef.cpp)

add_executable(server 
	src/Server.cpp
	src/SocDef.cpp)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests 
	unit_tests/unit_test_server.cpp 
	)
	# unit_tests/socket_mock.cpp
	# src/SocDef.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread GTest::gmock GTest::gmock_main)