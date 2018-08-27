#include "/opt/ros/kinetic/include/ros/ros.h"
#include "ros_tutorials_service/SrvTutorial.h"

//サービス要請があった場合呼び出される関数
bool calculation(ros_tutorials_service::SrvTutorial::Request &req,
                ros_tutorials_service::SrvTutorial::Response &res)
{
    res.result=req.a+req.b;

    ROS_INFO("request: x=%ld,y=%ld",(long int)req.a,(long int)req.b);
    ROS_INFO("sending back respoce: %ld",(long int)res.result);
    return true;

}

int main(int argc,char **argv){
    ros::init(argc,argv,"service_server");
    ros::NodeHandle nh;

    //サービスサーバ宣言
    //srvファイルを用いてros_tutorial_service_serverを宣言
    //サービス名はros_tutorial_srvで、要請があった時の関数を登録
    ros::ServiceServer ros_tutorials_service_server=
        nh.advertiseService("ros_tutorial_srv",calculation);

    ROS_INFO("ready srv server!");
    ros::spin();
    return 0;

}