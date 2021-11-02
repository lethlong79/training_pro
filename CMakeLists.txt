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