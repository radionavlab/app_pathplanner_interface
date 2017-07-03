# app_pathplanner_interface

Demonstration path planner ROS service to take `geometry_msgs/PoseArray` requests, and return `nav_msgs/Path` responses.

To be used with [utmg-android-interface](https://github.com/radionavlab/utmg-android-interface).

## Setup
1. Clone repo into `~/catkin_ws/src/`
2. Run `catkin_make` from `~/catkin_ws/`

## Usage
1. Run `rosrun app_pathplanner_interface app_pathplanner_server` to start the server
2. Start client
    * If using [utmg-android-interface](https://github.com/radionavlab/utmg-android-interface), the client should be running automatically.
    * To use in-built C++ client for testing purposes, run `rosrun app_pathplanner_interface app_pathplanner_client`

