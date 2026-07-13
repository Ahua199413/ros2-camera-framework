# Architecture

## Goal

Build a small, modular ROS 2 camera pipeline that separates image acquisition,
analysis, and presentation into independent nodes. This makes failures easier to
isolate and lets individual algorithms be replaced without changing the complete
pipeline.

## Planned nodes

### `camera_node`

Responsibilities:

- Capture frames from a USB camera or video file.
- Apply timestamps and frame identifiers.
- Publish images using `sensor_msgs/msg/Image`.
- Expose camera source, resolution, and frame rate as parameters.

### `focus_node`

Responsibilities:

- Subscribe to camera images.
- Convert ROS images to OpenCV matrices through `cv_bridge`.
- Calculate Laplacian variance and Tenengrad scores.
- Evaluate a configurable focus ROI.
- Publish focus metrics and an optional annotated image.

### `image_quality_node` (later milestone)

Responsibilities:

- Calculate brightness, contrast, and histogram statistics.
- Publish diagnostic data without coupling it to focus evaluation.

### Visualization and logging

Responsibilities:

- Display raw and annotated images using standard ROS tools.
- Plot numeric focus metrics.
- Record selected topics for repeatable offline analysis.

## Initial ROS interfaces

Names and message choices are provisional until the first package is implemented.

| Topic | Message type | Publisher | Subscriber |
|---|---|---|---|
| `/camera/image_raw` | `sensor_msgs/msg/Image` | `camera_node` | `focus_node` |
| `/focus/score` | `std_msgs/msg/Float64` | `focus_node` | visualization/logger |
| `/focus/state` | `std_msgs/msg/String` | `focus_node` | visualization/logger |
| `/focus/image_annotated` | `sensor_msgs/msg/Image` | `focus_node` | image viewer |

## Design principles

- Prefer standard ROS message types during the learning phase.
- Keep capture and analysis in separate processes.
- Make algorithm thresholds and ROI settings ROS parameters.
- Support video-file input so development does not always require a camera.
- Add custom messages only when standard messages no longer express the data well.

