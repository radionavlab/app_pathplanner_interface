#include "ros/ros.h"
#include "app_pathplanner_interface/PathPlanner.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/PoseArray.h"
#include "geometry_msgs/PoseStamped.h"
#include <cstdlib>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "app_pathplanner_client");
//  if (argc != 3)
//  {
//    ROS_INFO("usage: app_pathplanner_client X Y");
//    return 1;
//  }

	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<app_pathplanner_interface::PathPlanner>("app_pathplanner");
	app_pathplanner_interface::PathPlanner srv;

	geometry_msgs::PoseArray input_pose_array;
	
	std::vector<geometry_msgs::Pose> temp_vector;
		geometry_msgs::Pose temp_pose;
		temp_pose.position.x = 1.0;
		temp_pose.position.y = 2.0;
		temp_pose.position.z = 3.0;
	temp_vector.push_back(temp_pose);
	
	input_pose_array.poses = temp_vector;
	
	srv.request.input = input_pose_array;
	
//  srv.request.input = atoll(argv[1]);
//  srv.request.b = atoll(argv[2]);

	if (client.call(srv))
	{
		ROS_INFO("\nx: %f\ny: %f\nz: %f",	srv.response.output.poses[0].pose.position.x,
								      		srv.response.output.poses[0].pose.position.y,
								      		srv.response.output.poses[0].pose.position.z);
	}
	
	else
	{
		ROS_ERROR("Failed to call service app_pathplanner");
    	return 1;
    }

	return 0;
}
