#include"ros/ros.h"
#include"ros_tutorials_topic/MsgTutorial.h"

//自動生成されるヘッダファイル
int main(int argc,char **argv)
{
    //ノード名の初期化
    ros::init(argc,argv,"topic_publisher");
    //ROSシステムと通信を行うためのノードハンドルの宣言
    ros::NodeHandle nh;

    ros::Publisher ros_tutorial_pub=nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorial_msg",100);
    ros::Rate loop_rate(10);
    ros_tutorials_topic::MsgTutorial msg;
    int count=0;

    while(ros::ok())
    {
        msg.stamp=ros::Time::now();
        msg.data=count;
        ROS_INFO("send msg = %d",msg.stamp.sec);
        ROS_INFO("send msg = %d",msg.stamp.nsec);
        ROS_INFO("send msg = %d",msg.data);

        ros_tutorial_pub.publish(msg);
        loop_rate.sleep();
        count++;
        
    }
}