# ROS 2 Learning Roadmap

Each phase should end with a working, documented result. Commands and observations
from the Ubuntu host can be added to this directory as the project progresses.

## Phase 0: Environment

- Connect from the Mac to the Ubuntu workstation over SSH.
- Confirm Ubuntu 24.04, compiler, Python, CMake, and Git versions.
- Install ROS 2 Jazzy Desktop and `colcon` tools.
- Run the ROS 2 talker/listener demo.

**Done when:** two demo nodes exchange messages and `ros2 topic list` works.

## Phase 1: ROS 2 fundamentals

- Create an `ament_cmake` package.
- Implement one publisher and one subscriber.
- Inspect nodes and topics with the ROS 2 CLI.
- Learn message types, Quality of Service basics, and callback execution.

**Done when:** a self-written publisher and subscriber communicate reliably.

## Phase 2: Camera transport

- Capture a USB camera or video file with OpenCV.
- Publish frames as `sensor_msgs/msg/Image`.
- Subscribe and convert frames using `cv_bridge`.
- Inspect frame rate, timestamps, and image encoding.

**Done when:** an image travels through two independent ROS nodes.

## Phase 3: Focus analysis

- Implement Laplacian variance.
- Implement Tenengrad.
- Add configurable ROI and thresholds as ROS parameters.
- Publish numeric scores and an annotated image.

**Done when:** recorded sharp and blurred inputs produce explainable results.

## Phase 4: Application structure

- Start the pipeline with a launch file.
- Load parameters from YAML.
- Add tests for focus metrics.
- Add logging and rosbag-based replay.

**Done when:** one command starts a reproducible, configurable pipeline.

## Phase 5: Portfolio release

- Capture architecture and ROS graph screenshots.
- Report frame rate, latency, and CPU/GPU environment.
- Add a short demo and complete build/run instructions.
- Document design decisions and future work.

**Done when:** another ROS 2 Jazzy user can reproduce the demo from the README.

