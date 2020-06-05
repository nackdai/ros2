project(pubsub)

add_executable(pub pub.cpp)
target_include_directories(pub PRIVATE ${rclcpp_INCLUDE_DIRS}
                                       ${std_msgs_INCLUDE_DIRS})
target_link_libraries(pub ${rclcpp_LIBRARIES} ${std_msgs_LIBRARIES})

add_executable(sub sub.cpp)
target_include_directories(sub PRIVATE ${rclcpp_INCLUDE_DIRS}
                                       ${std_msgs_INCLUDE_DIRS})
target_link_libraries(sub ${rclcpp_LIBRARIES} ${std_msgs_LIBRARIES})
