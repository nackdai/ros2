#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>
#include <memory>

class Display : public rclcpp::Node {
 public:
  Display(const rclcpp::NodeOptions& options);

 private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;

  void display_greeting(const std_msgs::msg::String::SharedPtr msg);
};

Display::Display(const rclcpp::NodeOptions& options)
    : rclcpp::Node("displayer", options) {
  sub_ = create_subscription<std_msgs::msg::String>(
      "greeting", 10,
      std::bind(&Display::display_greeting, this, std::placeholders::_1));
}

void Display::display_greeting(const std_msgs::msg::String::SharedPtr msg) {
  RCLCPP_INFO(get_logger(), "Received greeting '%s'", msg->data.c_str());
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  rclcpp::NodeOptions options;
  auto receiver = std::make_shared<Display>(options);

  rclcpp::spin(receiver);
  rclcpp::shutdown();

  return 0;
}
