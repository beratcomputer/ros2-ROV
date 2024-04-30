// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/Pixhawk.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__PIXHAWK__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__PIXHAWK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/pixhawk__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Pixhawk_yaw
{
public:
  explicit Init_Pixhawk_yaw(::my_robot_interfaces::msg::Pixhawk & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::Pixhawk yaw(::my_robot_interfaces::msg::Pixhawk::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::Pixhawk msg_;
};

class Init_Pixhawk_pitch
{
public:
  explicit Init_Pixhawk_pitch(::my_robot_interfaces::msg::Pixhawk & msg)
  : msg_(msg)
  {}
  Init_Pixhawk_yaw pitch(::my_robot_interfaces::msg::Pixhawk::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Pixhawk_yaw(msg_);
  }

private:
  ::my_robot_interfaces::msg::Pixhawk msg_;
};

class Init_Pixhawk_roll
{
public:
  Init_Pixhawk_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pixhawk_pitch roll(::my_robot_interfaces::msg::Pixhawk::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Pixhawk_pitch(msg_);
  }

private:
  ::my_robot_interfaces::msg::Pixhawk msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::Pixhawk>()
{
  return my_robot_interfaces::msg::builder::Init_Pixhawk_roll();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__PIXHAWK__BUILDER_HPP_
