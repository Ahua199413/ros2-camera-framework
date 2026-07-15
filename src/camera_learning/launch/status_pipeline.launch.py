import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    package_share = get_package_share_directory("camera_learning")

    parameters_file = os.path.join(
        package_share,
        "config",
        "status_publisher.yaml"
    )

    return LaunchDescription([
        Node(
            package="camera_learning",
            executable="status_publisher",
            name="status_publisher",
            parameters=[parameters_file],
            output="screen",
        ),
        Node(
            package="camera_learning",
            executable="status_subscriber",
            name="status_subscriber",
            output="screen",
        ),
    ])