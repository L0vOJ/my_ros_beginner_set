#include <ros/ros.h>
#include <std_msgs/Int16.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "pub_node");
	ros::NodeHandle nh;

	ros::Publisher pub_number = nh.advertise<std_msgs::Int16>("/test/topic",10,true);
	//false가 default값
	//false일때 roscore에 등록 확인 안하고 진행 -> pub 진행이 먼서 완료되서 0값이 전송 안됨 
	//true일때 roscore에 등록 확인하고 진행 -> pub 등록 온전히 끝나고 전송되서 놓치는거 x 
	ros::Rate loop_rate(1);	//rate 설정 
	std_msgs::Int16 count; 	//메세지 타입 선언 

	while(ros::ok()){
		pub_number.publish(count);
		ROS_INFO("pub %d",count.data);
		count.data++;

		ros::spinOnce();	//한 번만 실행 
		loop_rate.sleep();	//앞서 정해진 rate만큼 대기 
	}
}