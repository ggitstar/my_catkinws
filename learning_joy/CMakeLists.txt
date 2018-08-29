cmake_minimum_required(VERSION 2.8.3)
project(learning_joy)

find_package(catkin REQUIRED COMPONENTS
  joy
  roscpp
  turtlesim
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES learning_joy
  CATKIN_DEPENDS joy roscpp turtlesim
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

 add_executable(turtle_teleop_joy src/turtle_teleop_joy.cpp)
# add_dependencies(turtle_teleop_joy ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
 target_link_libraries(turtle_teleop_joy  ${catkin_LIBRARIES} )