cmake_minimum_required(VERSION 3.8)
project(camera_learning)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(hello_node src/hello_node.cpp)

ament_target_dependencies(
  hello_node
  rclcpp
)
add_executable(status_publisher src/status_publisher.cpp)

ament_target_dependencies(
  status_publisher
  rclcpp
  std_msgs
)
install(
  TARGETS hello_node
          status_publisher
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()