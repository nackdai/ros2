#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <string>

class ParamHolder : public rclcpp::Node {
 public:
  ParamHolder(const rclcpp::NodeOptions& options);
};

ParamHolder::ParamHolder(const rclcpp::NodeOptions& options)
    : rclcpp::Node("test_node", options) {}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  rclcpp::NodeOptions options;
  auto param_holder = std::make_shared<ParamHolder>(options);

  param_holder->declare_parameter("param1", 0);
  param_holder->declare_parameter("param2", 0.0);
  param_holder->declare_parameter("param3", "");
  param_holder->declare_parameter("param4", true);
  std::vector<int64_t> param5(2, 0);
  param_holder->declare_parameter("param5", param5);
  param_holder->declare_parameter("param6", std::vector<bool>(3, true));
  param_holder->declare_parameter("param7", std::vector<int64_t>(1, 0));
  param_holder->declare_parameter("param8", std::vector<double>(4, 0.0));
  param_holder->declare_parameter("param9", std::vector<std::string>(4, ""));

  auto a1 = param_holder->get_parameter("param1").as_int();
  auto a2 = param_holder->get_parameter("param2").as_double();
  auto a3 = param_holder->get_parameter("param3").as_string();
  auto a4 = param_holder->get_parameter("param4").as_bool();
  auto a5 = param_holder->get_parameter("param5").as_integer_array();
  auto a6 = param_holder->get_parameter("param6").as_bool_array();
  auto a7 = param_holder->get_parameter("param7").as_integer_array();
  auto a8 = param_holder->get_parameter("param8").as_double_array();
  auto a9 = param_holder->get_parameter("param9").as_string_array();

  std::cout << "param1: " << a1 << std::endl;
  std::cout << "param2: " << a2 << std::endl;
  std::cout << "param3: " << a3 << std::endl;
  std::cout << "param4: " << a4 << std::endl;
  std::cout << "param5: " << a5[0] << std::endl;
  std::cout << "param6: " << a6[0] << std::endl;
  std::cout << "param7: " << a7[0] << std::endl;
  std::cout << "param8: " << a8[0] << std::endl;
  std::cout << "param9: " << a9[0] << std::endl;

  return 1;
}
