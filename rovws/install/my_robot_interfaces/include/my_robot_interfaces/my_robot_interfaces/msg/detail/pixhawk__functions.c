// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/Pixhawk.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/pixhawk__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
my_robot_interfaces__msg__Pixhawk__init(my_robot_interfaces__msg__Pixhawk * msg)
{
  if (!msg) {
    return false;
  }
  // roll
  // pitch
  // yaw
  return true;
}

void
my_robot_interfaces__msg__Pixhawk__fini(my_robot_interfaces__msg__Pixhawk * msg)
{
  if (!msg) {
    return;
  }
  // roll
  // pitch
  // yaw
}

bool
my_robot_interfaces__msg__Pixhawk__are_equal(const my_robot_interfaces__msg__Pixhawk * lhs, const my_robot_interfaces__msg__Pixhawk * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__Pixhawk__copy(
  const my_robot_interfaces__msg__Pixhawk * input,
  my_robot_interfaces__msg__Pixhawk * output)
{
  if (!input || !output) {
    return false;
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  return true;
}

my_robot_interfaces__msg__Pixhawk *
my_robot_interfaces__msg__Pixhawk__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__Pixhawk * msg = (my_robot_interfaces__msg__Pixhawk *)allocator.allocate(sizeof(my_robot_interfaces__msg__Pixhawk), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__Pixhawk));
  bool success = my_robot_interfaces__msg__Pixhawk__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__Pixhawk__destroy(my_robot_interfaces__msg__Pixhawk * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__Pixhawk__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__Pixhawk__Sequence__init(my_robot_interfaces__msg__Pixhawk__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__Pixhawk * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__Pixhawk *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__Pixhawk), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__Pixhawk__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__Pixhawk__fini(&data[i - 1]);
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
my_robot_interfaces__msg__Pixhawk__Sequence__fini(my_robot_interfaces__msg__Pixhawk__Sequence * array)
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
      my_robot_interfaces__msg__Pixhawk__fini(&array->data[i]);
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

my_robot_interfaces__msg__Pixhawk__Sequence *
my_robot_interfaces__msg__Pixhawk__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__Pixhawk__Sequence * array = (my_robot_interfaces__msg__Pixhawk__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__Pixhawk__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__Pixhawk__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__Pixhawk__Sequence__destroy(my_robot_interfaces__msg__Pixhawk__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__Pixhawk__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__Pixhawk__Sequence__are_equal(const my_robot_interfaces__msg__Pixhawk__Sequence * lhs, const my_robot_interfaces__msg__Pixhawk__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__Pixhawk__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__Pixhawk__Sequence__copy(
  const my_robot_interfaces__msg__Pixhawk__Sequence * input,
  my_robot_interfaces__msg__Pixhawk__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__Pixhawk);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__Pixhawk * data =
      (my_robot_interfaces__msg__Pixhawk *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__Pixhawk__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__Pixhawk__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__Pixhawk__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
