#include <ros/ros.h>
#include <my_msgs/SensorData.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "pub_node");
	ros::NodeHandle nh;

	ros::Publisher pub_number = nh.advertise<my_msgs::SensorData>("/test/topic",10,true);
	
	ros::Rate loop_rate(1);	//rate 설정 
	my_msgs::SensorData count; 	//메세지 타입 선언
	
	while(ros::ok()){
		pub_number.publish(count);
		ROS_INFO("pub %d",count.data);
		count.data++;

		ros::spinOnce();	//한 번만 실행 
		loop_rate.sleep();	//앞서 정해진 rate만큼 대기 
	}
}