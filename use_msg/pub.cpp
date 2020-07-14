#include <rclcpp/rclcpp.hpp>
#include "greeting_msg/msg/greeting.hpp"

#include <chrono>
#include <memory>

class Greeter : public rclcpp::Node {
 public:
  Greeter(const rclcpp::NodeOptions& options);

 private:
  void broadcast_greeting();

  rclcpp::Publisher<greeting_msg::msg::Greeting>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

Greeter::Greeter(const rclcpp::NodeOptions& options)
    : rclcpp::Node("greeting", options) {
  pub_ = create_publisher<greeting_msg::msg::Greeting>("greeting", 10);
  timer_ = create_wall_timer(std::chrono::seconds(1),
                             std::bind(&Greeter::broadcast_greeting, this));
}

void Greeter::broadcast_greeting() {
  auto greeting = std::make_shared<greeting_msg::msg::Greeting>();
  greeting->hello_text = "hello";
  greeting->world_name = "world";
  greeting->count = 11;
  RCLCPP_INFO(get_logger(), "Publishing greeting '%s'",
              greeting->hello_text.c_str());
  pub_->publish(*greeting);
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  auto greeter = std::make_shared<Greeter>(options);
  rclcpp::spin(greeter);

  rclcpp::shutdown();
  return 0;
}
