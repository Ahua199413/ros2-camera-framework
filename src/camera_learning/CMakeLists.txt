cmake_minimum_required(VERSION 3.8)
project(camera_learning)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)

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
  std_srvs
)

add_executable(status_subscriber src/status_subscriber.cpp)

ament_target_dependencies(
  status_subscriber
  rclcpp
  std_msgs
)
install(
  TARGETS hello_node
          status_publisher
          status_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY
    config
    launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()