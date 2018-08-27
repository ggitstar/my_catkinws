#ビルドに最低限必要なバージョン
cmake_minimum_required(VERSION 2.8.3)
#パッケージ名xmlファイルと違ったらエラー
project(my_first_ros_pkg)
#catkinビルドの実行時に要求される依存パッケージ
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)
#catkinビルドのオプションincludeフォルダのヘッダを参照 pkgにあるライブラリを参照　依存関係　システム依存
catkin_package(CATKIN_DEPENDS roscpp std_msgs)
#インクルードフォルダ　各パッケージのincludeフォルダ
include_directories(${catkin_INCLUDE_DIRS})
#ビルド後生成するファイルを指定
add_executable(hello_world_node src/hello_world_node.cpp)
#実行ファイルを生成する際に必要なライブラリ
target_link_libraries(hello_world_node ${catkin_LIBRARIES})