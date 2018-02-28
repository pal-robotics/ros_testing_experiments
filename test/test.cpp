/**************************************************************************
**
**  File: gtest_ros_testing_experiments
**
**  Author: victor
**  Created on: 2017/4/13
**
**  Copyright (c) 2017 PAL Robotics SL. All Rights Reserved
**************************************************************************/

#include <gtest/gtest.h>
#include <ros/ros.h>

TEST(CppTest, test1)
{
  std::cout << ros::this_node::getName() << " stdout" << std::endl;
  std::cerr << ros::this_node::getName() << " stderr" << std::endl;
  ROS_DEBUG_STREAM(ros::this_node::getName() << " Debug");
  ROS_INFO_STREAM(ros::this_node::getName() << " Info");
  ROS_WARN_STREAM(ros::this_node::getName() << " Warn");
  ROS_ERROR_STREAM(ros::this_node::getName() << " Error");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cpp_test");
  // first nodehandle created of an app must exist until the end of the life of the node
  // If not, you'll have funny stuff such as no logs printed
  ros::NodeHandle nh;

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
