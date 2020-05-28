cmake_minimum_required(VERSION 3.10.0)

project(ros2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

execute_process(COMMAND
    bash -c "cd ${CMAKE_CURRENT_SOURCE_DIR}/messages && colcon build")

function(include_package package)
    set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/messages/install/${package})
    find_package(${package} REQUIRED)
endfunction()

include_package(greeting_msg)

add_subdirectory(pubsub)
