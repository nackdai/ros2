#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>
#include <memory>

class ParamClient : public rclcpp::Node
{
public:
  ParamClient(const rclcpp::NodeOptions& options);

private:
  rclcpp::SyncParametersClient::SharedPtr params_;
};

ParamClient::ParamClient(const rclcpp::NodeOptions& options) : rclcpp::Node("param_client", options)
{
  params_ = std::make_shared<rclcpp::SyncParametersClient>(this, "param_server");

  while (!params_->wait_for_service(std::chrono::seconds(1)))
  {
    std::cout << "waiting for service" << std::endl;
  }

  auto get_params = params_->get_parameters({ "foo", "bar" });
  for (auto& param : get_params)
  {
    std::cout << "Name: " << param.get_name() << std::endl;
    std::cout << "Type: " << param.get_type_name() << std::endl;
    std::cout << "Value: " << param.value_to_string() << std::endl;
  }

  // Set parameters from client
  auto parameter_set_results = params_->set_parameters({ rclcpp::Parameter("foo", 3),  //
                                                         rclcpp::Parameter("bar", "welcome") });

  for (auto& result : parameter_set_results)
  {
    if (!result.successful)
    {
      std::cout << "Failed to set parameter: " << result.reason << std::endl;
    }
  }

  std::cout << "**** Modified ****" << std::endl;

  get_params = params_->get_parameters({ "foo", "bar" });
  for (auto& param : get_params)
  {
    std::cout << "Name: " << param.get_name() << std::endl;
    std::cout << "Type: " << param.get_type_name() << std::endl;
    std::cout << "Value: " << param.value_to_string() << std::endl;
  }
}

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::NodeOptions options;
  rclcpp::spin(std::make_shared<ParamClient>(options));
  rclcpp::shutdown();
  return 0;
}
