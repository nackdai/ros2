project(use_custom_msg)

set(greeting_msg_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/messages/install/include)

file(GLOB libs ${CMAKE_BINARY_DIR}/messages/*.so)
set(greeting_msg_LIBRARIES ${libs})

add_executable(use_custom_msg_pub pub.cpp)
target_include_directories(use_custom_msg_pub PRIVATE ${rclcpp_INCLUDE_DIRS} ${greeting_msg_INCLUDE_DIRS})
target_link_libraries(use_custom_msg_pub ${rclcpp_LIBRARIES} ${greeting_msg_LIBRARIES})
