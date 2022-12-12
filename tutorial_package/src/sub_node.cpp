#include <ros/ros.h>
#include <std_msgs/Int16.h>

void NumberCallback(const std_msgs::Int16 &msg)
{
	ROS_INFO("sub %d",msg.data);
}

int main(int argc, char** argv){
	ros::init(argc, argv, "sub_node");
	ros::NodeHandle nh;

	ros::Subscriber sub_number = nh.subscribe("/test/topic",10,NumberCallback);

	ros::spin();
}