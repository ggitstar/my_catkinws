cmake_minimum_required(VERSION 2.8.3)
project(ros_tutorials_service)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

##srvフォルダの中を参照
 add_service_files(
   FILES
   SrvTutorial.srv
 )

 generate_messages(
   DEPENDENCIES
   std_msgs  # Or other packages containing msgs
 )

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES ros_tutorials_service
  CATKIN_DEPENDS message_generation roscpp std_msg
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
 add_executable(service_server src/service_server.cpp)
 add_dependencies(service_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
 target_link_libraries(service_server ${catkin_LIBRARIES})

 add_executable(service_client src/service_client.cpp)
 add_dependencies(service_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
 target_link_libraries(service_client ${catkin_LIBRARIES})
