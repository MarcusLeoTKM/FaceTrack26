// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/OffsetPX.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "messages/msg/offset_px.hpp"


#ifndef MESSAGES__MSG__DETAIL__OFFSET_PX__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__OFFSET_PX__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__msg__OffsetPX __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__OffsetPX __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OffsetPX_
{
  using Type = OffsetPX_<ContainerAllocator>;

  explicit OffsetPX_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->offset_px = 0.0;
    }
  }

  explicit OffsetPX_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->offset_px = 0.0;
    }
  }

  // field types and members
  using _offset_px_type =
    double;
  _offset_px_type offset_px;

  // setters for named parameter idiom
  Type & set__offset_px(
    const double & _arg)
  {
    this->offset_px = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::OffsetPX_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::OffsetPX_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::OffsetPX_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::OffsetPX_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::OffsetPX_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::OffsetPX_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::OffsetPX_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::OffsetPX_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::OffsetPX_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::OffsetPX_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__OffsetPX
    std::shared_ptr<messages::msg::OffsetPX_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__OffsetPX
    std::shared_ptr<messages::msg::OffsetPX_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OffsetPX_ & other) const
  {
    if (this->offset_px != other.offset_px) {
      return false;
    }
    return true;
  }
  bool operator!=(const OffsetPX_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OffsetPX_

// alias to use template instance with default allocator
using OffsetPX =
  messages::msg::OffsetPX_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__OFFSET_PX__STRUCT_HPP_
