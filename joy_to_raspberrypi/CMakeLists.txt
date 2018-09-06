cmake_minimum_required(VERSION 2.8.3)
project(joy_to_raspberrypi)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
#  cont_msg
)

# catkin_python_setup()
## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   Controller.msg
 )

# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES joy_to_raspberrypi
  CATKIN_DEPENDS message_generation roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/joy_to_raspberrypi.cpp
# )

 add_executable(joy_to_raspberrypi src/joy_to_raspberrypi.py)
 add_dependencies(joy_to_raspberrypi ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
 target_link_libraries(joy_to_raspberrypi ${catkin_LIBRARIES})


