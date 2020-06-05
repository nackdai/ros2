project(tf)

add_executable(static_tf_pub static_tf2_broadcaster.cpp)
target_include_directories(
  static_tf_pub
  PRIVATE ${rclcpp_INCLUDE_DIRS} ${std_msgs_INCLUDE_DIRS}
          ${geometry_msgs_INCLUDE_DIRS} ${tf2_ros_INCLUDE_DIRS}
          ${tf2_geometry_msgs_INCLUDE_DIRS})
target_link_libraries(
  static_tf_pub
  ${rclcpp_LIBRARIES}
  ${std_msgs_LIBRARIES}
  ${geometry_msgs_LIBRARIES}
  ${tf2_LIBRARIES}
  ${tf2_ros_LIBRARIES}
  ${tf2_geometry_msgs_LIBRARIES})
