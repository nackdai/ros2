project(greeting_msg)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME} "msg/Greeting.msg")

ament_export_dependencies(rosidl_default_runtime)

ament_package()

add_custom_command(
  TARGET greeting_msg
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory
          "${greeting_msg_BINARY_DIR}/install/lib")
add_custom_command(
  TARGET greeting_msg
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy "${greeting_msg_BINARY_DIR}/*.so"
          "${greeting_msg_BINARY_DIR}/install/lib")

add_custom_command(
  TARGET greeting_msg
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory
          "${greeting_msg_BINARY_DIR}/install/include/${PROJECT_NAME}/msg")
add_custom_command(
  TARGET greeting_msg
  POST_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy
    "${greeting_msg_BINARY_DIR}/rosidl_generator_cpp/${PROJECT_NAME}/msg/*"
    "${greeting_msg_BINARY_DIR}/install/include/${PROJECT_NAME}/msg")
