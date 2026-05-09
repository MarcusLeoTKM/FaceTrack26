// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from messages:msg/OffsetPX.idl
// generated code does not contain a copyright notice

#include "messages/msg/detail/offset_px__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_messages
const rosidl_type_hash_t *
messages__msg__OffsetPX__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x95, 0xcb, 0xd0, 0xd8, 0x52, 0xd9, 0x1b, 0x55,
      0xb0, 0x86, 0x3e, 0xcb, 0xa6, 0xd9, 0x49, 0x32,
      0x51, 0x6b, 0xb3, 0x92, 0xb9, 0x5e, 0x15, 0xcc,
      0x4f, 0xd9, 0x7a, 0xbc, 0x63, 0x18, 0x6c, 0xae,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char messages__msg__OffsetPX__TYPE_NAME[] = "messages/msg/OffsetPX";

// Define type names, field names, and default values
static char messages__msg__OffsetPX__FIELD_NAME__offset_px[] = "offset_px";

static rosidl_runtime_c__type_description__Field messages__msg__OffsetPX__FIELDS[] = {
  {
    {messages__msg__OffsetPX__FIELD_NAME__offset_px, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
messages__msg__OffsetPX__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {messages__msg__OffsetPX__TYPE_NAME, 21, 21},
      {messages__msg__OffsetPX__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 offset_px";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
messages__msg__OffsetPX__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {messages__msg__OffsetPX__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 18, 18},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
messages__msg__OffsetPX__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *messages__msg__OffsetPX__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
