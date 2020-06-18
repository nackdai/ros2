#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <string>

class ParamServer : public rclcpp::Node {
 public:
  ParamServer(const rclcpp::NodeOptions& options);
};

ParamServer::ParamServer(const rclcpp::NodeOptions& options)
    : rclcpp::Node("param_server", options) {
  auto param1 = declare_parameter("foo", 0);
  auto param2 = declare_parameter("bar", "ok");
  auto results = set_parameters(
      {rclcpp::Parameter("foo", 2), rclcpp::Parameter("bar", "hello")});
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  rclcpp::spin(std::make_shared<ParamServer>(options));
  rclcpp::shutdown();
  return 0;
}
