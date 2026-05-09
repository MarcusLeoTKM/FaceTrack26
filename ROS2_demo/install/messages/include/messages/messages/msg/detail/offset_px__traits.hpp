// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/OffsetPX.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "messages/msg/offset_px.hpp"


#ifndef MESSAGES__MSG__DETAIL__OFFSET_PX__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__OFFSET_PX__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/offset_px__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const OffsetPX & msg,
  std::ostream & out)
{
  out << "{";
  // member: offset_px
  {
    out << "offset_px: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_px, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OffsetPX & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: offset_px
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_px: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_px, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OffsetPX & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::msg::OffsetPX & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::OffsetPX & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::OffsetPX>()
{
  return "messages::msg::OffsetPX";
}

template<>
inline const char * name<messages::msg::OffsetPX>()
{
  return "messages/msg/OffsetPX";
}

template<>
struct has_fixed_size<messages::msg::OffsetPX>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<messages::msg::OffsetPX>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<messages::msg::OffsetPX>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__OFFSET_PX__TRAITS_HPP_
