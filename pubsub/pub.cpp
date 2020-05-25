#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>
#include <memory>

class Greeter : public rclcpp::Node {
 public:
  Greeter(const rclcpp::NodeOptions& options);

 private:
  void broadcast_greeting();

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

Greeter::Greeter(const rclcpp::NodeOptions& options)
    : rclcpp::Node("greeting", options) {
  pub_ = create_publisher<std_msgs::msg::String>("greeting", 10);
  timer_ = create_wall_timer(std::chrono::seconds(1),
                             std::bind(&Greeter::broadcast_greeting, this));
}

void Greeter::broadcast_greeting() {
  auto greeting = std::make_shared<std_msgs::msg::String>();
  greeting->data = "hello world";
  RCLCPP_INFO(get_logger(), "Publishing greeting '%s'", greeting->data.c_str());
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
