#include <vector>
#include "ros/ros.h"
#include "app_pathplanner_interface/PathPlanner.h"
#include "nav_msgs/Path.h"
#include "geometry_msgs/PoseStamped.h"

bool transform(app_pathplanner_interface::PathPlanner::Request &req,
               app_pathplanner_interface::PathPlanner::Response &res)
{


	nav_msgs::Path output_path;
	
	std::vector<geometry_msgs::PoseStamped> temp_vector;
	geometry_msgs::PoseStamped temp_pose_stamped;
	temp_vector.push_back(temp_pose_stamped);
	
	output_path.poses = temp_vector;

	output_path.poses[0].pose.position.x = req.input.poses.at(0).position.x;	
	output_path.poses[0].pose.position.y = req.input.poses.at(0).position.y;
	output_path.poses[0].pose.position.z = req.input.poses.at(0).position.z;
	
	res.output = output_path;
	

  ROS_INFO("request: x=%f, y=%f, z=%f", req.input.poses.at(0).position.x,
  										req.input.poses.at(0).position.y,
  										req.input.poses.at(0).position.z);
  										
  ROS_INFO("sending back response: x=%f, y=%f, z=%f",	output_path.poses[0].pose.position.x,
  														output_path.poses[0].pose.position.y,
  														output_path.poses[0].pose.position.z);

	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "app_pathplanner_server");
	ros::NodeHandle n;

	ros::ServiceServer service = n.advertiseService("app_pathplanner", transform);
	ROS_INFO("Ready to transform PoseArray into Path.");
	ros::spin();

	return 0;
}

