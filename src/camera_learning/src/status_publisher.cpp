#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_srvs/srv/set_bool.hpp"

using namespace std::chrono_literals;

class StatusPublisher : public rclcpp::Node {
private:
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr enable_service_;
  bool enabled_{true};

  void set_enabled(
    const std::shared_ptr<std_srvs::srv::SetBool::Request> request,
    std::shared_ptr<std_srvs::srv::SetBool::Response> response)
  {
    enabled_ = request->data;

    response->success = true;
    response->message = enabled_ ? "Camera status publishing enabled" : "Camera status publishing disabled";

    RCLCPP_INFO(
      this->get_logger(),
      "%s",
      response->message.c_str()
    );
  }


  void publish_status() {
    if (!enabled_) {
      return;
    }

    auto message = std_msgs::msg::String();
    message.data = this->get_parameter("status_message").as_string();
    publisher_->publish(message);

    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  }


public:
  StatusPublisher() : Node("status_publisher") {
    this->declare_parameter<std::string>(
        "status_message",
        "Camera running"
    );

    publisher_ =
        this->create_publisher<std_msgs::msg::String>(
          "/camera/status", 10);

    timer_ = this->create_wall_timer(
        1s, std::bind(&StatusPublisher::publish_status, this));

    enable_service_ =
      this->create_service<std_srvs::srv::SetBool>(
        "/camera/set_enabled",
        std::bind(
          &StatusPublisher::set_enabled,
          this,
          std::placeholders::_1,
          std::placeholders::_2));
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<StatusPublisher>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}