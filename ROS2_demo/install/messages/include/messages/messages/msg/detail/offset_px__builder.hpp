// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/OffsetPX.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "messages/msg/offset_px.hpp"


#ifndef MESSAGES__MSG__DETAIL__OFFSET_PX__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__OFFSET_PX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/offset_px__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_OffsetPX_offset_px
{
public:
  Init_OffsetPX_offset_px()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::messages::msg::OffsetPX offset_px(::messages::msg::OffsetPX::_offset_px_type arg)
  {
    msg_.offset_px = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::OffsetPX msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::OffsetPX>()
{
  return messages::msg::builder::Init_OffsetPX_offset_px();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__OFFSET_PX__BUILDER_HPP_
