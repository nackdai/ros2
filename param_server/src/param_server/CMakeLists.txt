cmake_minimum_required(VERSION 3.5)

project(param_server)

set(CMAKE_CXX_STANDARD 14)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(param_server param_server.cpp)

ament_target_dependencies(param_server rclcpp std_msgs)

install(TARGETS param_server DESTINATION lib/${PROJECT_NAME})

ament_package()
