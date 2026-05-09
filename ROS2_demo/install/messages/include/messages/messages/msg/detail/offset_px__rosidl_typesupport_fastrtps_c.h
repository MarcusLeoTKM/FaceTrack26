// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from messages:msg/OffsetPX.idl
// generated code does not contain a copyright notice
#ifndef MESSAGES__MSG__DETAIL__OFFSET_PX__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define MESSAGES__MSG__DETAIL__OFFSET_PX__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "messages/msg/detail/offset_px__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
bool cdr_serialize_messages__msg__OffsetPX(
  const messages__msg__OffsetPX * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
bool cdr_deserialize_messages__msg__OffsetPX(
  eprosima::fastcdr::Cdr &,
  messages__msg__OffsetPX * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t get_serialized_size_messages__msg__OffsetPX(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t max_serialized_size_messages__msg__OffsetPX(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
bool cdr_serialize_key_messages__msg__OffsetPX(
  const messages__msg__OffsetPX * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t get_serialized_size_key_messages__msg__OffsetPX(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t max_serialized_size_key_messages__msg__OffsetPX(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, messages, msg, OffsetPX)();

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__OFFSET_PX__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
