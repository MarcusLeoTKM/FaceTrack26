// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from messages:msg/OffsetPX.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/offset_px__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
messages__msg__OffsetPX__init(messages__msg__OffsetPX * msg)
{
  if (!msg) {
    return false;
  }
  // offset_px
  return true;
}

void
messages__msg__OffsetPX__fini(messages__msg__OffsetPX * msg)
{
  if (!msg) {
    return;
  }
  // offset_px
}

bool
messages__msg__OffsetPX__are_equal(const messages__msg__OffsetPX * lhs, const messages__msg__OffsetPX * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // offset_px
  if (lhs->offset_px != rhs->offset_px) {
    return false;
  }
  return true;
}

bool
messages__msg__OffsetPX__copy(
  const messages__msg__OffsetPX * input,
  messages__msg__OffsetPX * output)
{
  if (!input || !output) {
    return false;
  }
  // offset_px
  output->offset_px = input->offset_px;
  return true;
}

messages__msg__OffsetPX *
messages__msg__OffsetPX__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__OffsetPX * msg = (messages__msg__OffsetPX *)allocator.allocate(sizeof(messages__msg__OffsetPX), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(messages__msg__OffsetPX));
  bool success = messages__msg__OffsetPX__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
messages__msg__OffsetPX__destroy(messages__msg__OffsetPX * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    messages__msg__OffsetPX__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
messages__msg__OffsetPX__Sequence__init(messages__msg__OffsetPX__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__OffsetPX * data = NULL;

  if (size) {
    data = (messages__msg__OffsetPX *)allocator.zero_allocate(size, sizeof(messages__msg__OffsetPX), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = messages__msg__OffsetPX__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        messages__msg__OffsetPX__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
messages__msg__OffsetPX__Sequence__fini(messages__msg__OffsetPX__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      messages__msg__OffsetPX__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

messages__msg__OffsetPX__Sequence *
messages__msg__OffsetPX__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  messages__msg__OffsetPX__Sequence * array = (messages__msg__OffsetPX__Sequence *)allocator.allocate(sizeof(messages__msg__OffsetPX__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = messages__msg__OffsetPX__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
messages__msg__OffsetPX__Sequence__destroy(messages__msg__OffsetPX__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    messages__msg__OffsetPX__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
messages__msg__OffsetPX__Sequence__are_equal(const messages__msg__OffsetPX__Sequence * lhs, const messages__msg__OffsetPX__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!messages__msg__OffsetPX__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
messages__msg__OffsetPX__Sequence__copy(
  const messages__msg__OffsetPX__Sequence * input,
  messages__msg__OffsetPX__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(messages__msg__OffsetPX);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    messages__msg__OffsetPX * data =
      (messages__msg__OffsetPX *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!messages__msg__OffsetPX__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          messages__msg__OffsetPX__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!messages__msg__OffsetPX__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
