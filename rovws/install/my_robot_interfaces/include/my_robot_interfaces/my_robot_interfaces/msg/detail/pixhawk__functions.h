// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from my_robot_interfaces:msg/Pixhawk.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__PIXHAWK__FUNCTIONS_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__PIXHAWK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "my_robot_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "my_robot_interfaces/msg/detail/pixhawk__struct.h"

/// Initialize msg/Pixhawk message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * my_robot_interfaces__msg__Pixhawk
 * )) before or use
 * my_robot_interfaces__msg__Pixhawk__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
bool
my_robot_interfaces__msg__Pixhawk__init(my_robot_interfaces__msg__Pixhawk * msg);

/// Finalize msg/Pixhawk message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
void
my_robot_interfaces__msg__Pixhawk__fini(my_robot_interfaces__msg__Pixhawk * msg);

/// Create msg/Pixhawk message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * my_robot_interfaces__msg__Pixhawk__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
my_robot_interfaces__msg__Pixhawk *
my_robot_interfaces__msg__Pixhawk__create();

/// Destroy msg/Pixhawk message.
/**
 * It calls
 * my_robot_interfaces__msg__Pixhawk__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
void
my_robot_interfaces__msg__Pixhawk__destroy(my_robot_interfaces__msg__Pixhawk * msg);

/// Check for msg/Pixhawk message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
bool
my_robot_interfaces__msg__Pixhawk__are_equal(const my_robot_interfaces__msg__Pixhawk * lhs, const my_robot_interfaces__msg__Pixhawk * rhs);

/// Copy a msg/Pixhawk message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
bool
my_robot_interfaces__msg__Pixhawk__copy(
  const my_robot_interfaces__msg__Pixhawk * input,
  my_robot_interfaces__msg__Pixhawk * output);

/// Initialize array of msg/Pixhawk messages.
/**
 * It allocates the memory for the number of elements and calls
 * my_robot_interfaces__msg__Pixhawk__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
bool
my_robot_interfaces__msg__Pixhawk__Sequence__init(my_robot_interfaces__msg__Pixhawk__Sequence * array, size_t size);

/// Finalize array of msg/Pixhawk messages.
/**
 * It calls
 * my_robot_interfaces__msg__Pixhawk__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
void
my_robot_interfaces__msg__Pixhawk__Sequence__fini(my_robot_interfaces__msg__Pixhawk__Sequence * array);

/// Create array of msg/Pixhawk messages.
/**
 * It allocates the memory for the array and calls
 * my_robot_interfaces__msg__Pixhawk__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
my_robot_interfaces__msg__Pixhawk__Sequence *
my_robot_interfaces__msg__Pixhawk__Sequence__create(size_t size);

/// Destroy array of msg/Pixhawk messages.
/**
 * It calls
 * my_robot_interfaces__msg__Pixhawk__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
void
my_robot_interfaces__msg__Pixhawk__Sequence__destroy(my_robot_interfaces__msg__Pixhawk__Sequence * array);

/// Check for msg/Pixhawk message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
bool
my_robot_interfaces__msg__Pixhawk__Sequence__are_equal(const my_robot_interfaces__msg__Pixhawk__Sequence * lhs, const my_robot_interfaces__msg__Pixhawk__Sequence * rhs);

/// Copy an array of msg/Pixhawk messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_my_robot_interfaces
bool
my_robot_interfaces__msg__Pixhawk__Sequence__copy(
  const my_robot_interfaces__msg__Pixhawk__Sequence * input,
  my_robot_interfaces__msg__Pixhawk__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__PIXHAWK__FUNCTIONS_H_
