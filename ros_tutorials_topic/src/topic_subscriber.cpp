#include "/opt/ros/kinetic/include/ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"
//メッセージのコールバック関数ros_tutorial_msgトピックにてメッセージを受信したときに動作する参照渡し担っている
void msgCallback(const ros_tutorials_topic::MsgTutorial::ConstPtr& msg){
    ROS_INFO("receive msg=%d",msg->stamp.sec);
    ROS_INFO("receive msg=%d",msg->stamp.nsec);
    ROS_INFO("receive msg=%d",msg->data);

}

int main(int argc,char **argv){
    ros::init(argc,argv,"topic_subscriber");
    ros::NodeHandle nh;

    //サブスクライバの宣言
    //パッケージのMsgTutorial.msgファイルを用いたサブスクライバを作成
    //
    ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg",100,msgCallback);
    //コールバック関数を呼び出すための関数
    ros::spin();
    return 0;
}