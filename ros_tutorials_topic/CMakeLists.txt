cmake_minimum_required(VERSION 2.8.3)
project(ros_tutorials_topic)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

##ビルド実行時に要求される依存パッケージを変数に出力
find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

################################################
## Declare ROS messages, services and actions ##
################################################


##メッセージ宣言
 add_message_files(
   FILES
   MsgTutorial.msg
 )

##依存するメッセージを設定するオプション
##std_msgsが設置されていないと、ビルドの途中でエラーが生じる
 generate_messages(
   DEPENDENCIES
   std_msgs
 )

##catkinパッケージオプションであるライブラリ、catkinビルドの依存性
##システム依存パッケージについて記述する
##LIBRARIESでros_topic_tutorialsパッケージのライブラリを参照
##CATKIN_DEPENDSで依存関係が設定
catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES ros_tutorials_topic
  CATKIN_DEPENDS message_generation roscpp std_msgs
#  DEPENDS system_lib
)


## インクルードディレクトリを設定する各パッケージのincludeフォルダ
include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

#topic_publisherノードに対するビルドオプション
#実行ファイル、ターゲットライブラリ、追加依存性などについて記述する
#ビルド後生成する実行ファイルを指定
 add_executable(topic_publisher src/topic_publisher.cpp)
##ライブラリや実行ファイルを生成する前にせいせいする必要がある依存メッセージ
 add_dependencies(topic_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
##実行ファイル生成の際リンクが必要なライブラリ
 target_link_libraries(topic_publisher ${catkin_LIBRARIES})

 add_executable(topic_subscriber src/topic_subscriber.cpp)
 add_dependencies(topic_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
 target_link_libraries(topic_subscriber ${catkin_LIBRARIES})
