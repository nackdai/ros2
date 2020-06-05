#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <cstdio>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>
#include <memory>

// NOTE
// https://github.com/ros2/geometry2/tree/ros2/tf2_ros

class StaticTf2BroadcasterNode : public rclcpp::Node {
 public:
  StaticTf2BroadcasterNode(const rclcpp::NodeOptions& options);

 private:
  std::unique_ptr<tf2_ros::StaticTransformBroadcaster> static_broadcaster_;
};

StaticTf2BroadcasterNode::StaticTf2BroadcasterNode(
    const rclcpp::NodeOptions& options)
    : rclcpp::Node("static_tf2_broadcaster", options) {
  geometry_msgs::msg::TransformStamped static_transformStamped;
  static_transformStamped.header.stamp = this->now();
  static_transformStamped.header.frame_id = "world";
  static_transformStamped.child_frame_id = "child";

  static_transformStamped.transform.translation.x = 1.0;
  static_transformStamped.transform.translation.y = 2.0;
  static_transformStamped.transform.translation.z = 3.0;

  tf2::Quaternion quat;
  quat.setRPY(0.0, 0.0, 0.0);
  static_transformStamped.transform.rotation.x = quat.x();
  static_transformStamped.transform.rotation.y = quat.y();
  static_transformStamped.transform.rotation.z = quat.z();
  static_transformStamped.transform.rotation.w = quat.w();

  static_broadcaster_ =
      std::make_unique<tf2_ros::StaticTransformBroadcaster>(this);

  static_broadcaster_->sendTransform(static_transformStamped);
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  rclcpp::NodeOptions options;
  auto node = std::make_shared<StaticTf2BroadcasterNode>(options);

  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
