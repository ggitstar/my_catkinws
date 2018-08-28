#include "/opt/ros/kinetic/include/ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"

int main(int argc,char **argv){
    ros::init(argc,argv,"topic_publisher");
    //このプロセスでのノードへのハンドラ
    ros::NodeHandle nh;

    //パブリッシャの宣言
    //"ros_tutorials_topic"という名前のトピックにMagTutorial型タイプのメッセージを送ることを伝える
    ros::Publisher ros_tutorial_pub=nh.advertise<ros_tutorials_topic::MsgTutorial>
    ("ros_tutorial_msg",100);

    ros::Rate loop_rate(10);
    //MsgTutorial型のメッセージを適用
    ros_tutorials_topic::MsgTutorial msg;

    int count=0;

    while(ros::ok()){
        msg.stamp=ros::Time::now();
        msg.data=count;

        ROS_INFO("send msg=%d",msg.stamp.sec);
        ROS_INFO("send msg=%d",msg.stamp.nsec);
        ROS_INFO("send msg=%d",msg.data);
        ros_tutorial_pub.publish(msg);
        loop_rate.sleep();
        ++count;
    }
    return 0;
}