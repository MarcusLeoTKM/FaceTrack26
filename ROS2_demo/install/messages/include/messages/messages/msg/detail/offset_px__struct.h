// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/OffsetPX.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "messages/msg/offset_px.h"


#ifndef MESSAGES__MSG__DETAIL__OFFSET_PX__STRUCT_H_
#define MESSAGES__MSG__DETAIL__OFFSET_PX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/OffsetPX in the package messages.
typedef struct messages__msg__OffsetPX
{
  double offset_px;
} messages__msg__OffsetPX;

// Struct for a sequence of messages__msg__OffsetPX.
typedef struct messages__msg__OffsetPX__Sequence
{
  messages__msg__OffsetPX * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__msg__OffsetPX__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__DETAIL__OFFSET_PX__STRUCT_H_
