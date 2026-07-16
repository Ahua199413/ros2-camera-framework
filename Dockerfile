FROM ros:jazzy-ros-base-noble

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        git \
        nano \
        wget \
        ca-certificates \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        ros-jazzy-action-tutorials-cpp \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

CMD ["bash"]

RUN echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
