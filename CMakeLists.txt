cmake_minimum_required(VERSION 3.10.0)

option(BUILD_MSG "" OFF)

project(ros2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

if (BUILD_MSG)
    add_subdirectory(messages)
else()
    add_subdirectory(use_msg)
    add_subdirectory(pubsub)
    add_subdirectory(tf)
endif()
