cmake_minimum_required(VERSION 3.8)
project(my_robot_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)#burası haricen eklendi

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/HardwareStatus.msg"
  "msg/Pixhawk.msg"
  "msg/Turtle.msg"
  "msg/TurtleArray.msg"
  "srv/ComputeRectangleArea.srv"
)#eklediğin her yeni mesaj tipi dosyasının adını buraya girmelisin

ament_export_dependencies(rosidl_default_runtime)#burayı ament_package dan hemen önce eklemelisin
ament_package()
