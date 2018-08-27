#include"ros/ros.h"
#include"ros_tutorials_topic/MsgTutorial.h"
//自動生成されるヘッダファイル 
void msgCallBack(const ros_tutorials_topic::MsgTutorial::ConstPtr& msg){
        ROS_INFO("send msg = %d",msg->stamp.sec);
        ROS_INFO("send msg = %d",msg->stamp.nsec);
        ROS_INFO("send msg = %d",msg->data);
}
int main(int argc,char **argv)
{
    ros::init(argc,argv,"topic_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber ros_tutorial_sub=nh.subscribe("ros_tutorial_msg",100,msgCallBack);
    ros::spin();
    return 0;

}