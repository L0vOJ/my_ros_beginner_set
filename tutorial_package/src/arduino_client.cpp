#include <ros/ros.h>
#include <my_msgs/ReqRes.h>

int main(int argc, char** argv){
	ros::init(argc, argv, "client_node");
	ros::NodeHandle nh;

	ros::ServiceClient client = nh.serviceClient<my_msgs::ReqRes>("test_srv");
	
	ros::Rate loop_rate(1);	//rate 설정 
	
	int a=0, b=0;
	
	//while(ros::ok()){
	my_msgs::ReqRes srv;
	srv.request.input = argv[1];

	if(client.call(srv))
	{
		ROS_INFO("%s = %s",srv.request.input.c_str(),srv.response.output.c_str());
	}
	//loop_rate.sleep();	//앞서 정해진 rate만큼 대기 
	//}
}