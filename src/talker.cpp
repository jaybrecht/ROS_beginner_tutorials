// "Copyright [2020] Justin Albrecht"

#include <stdexcept>
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeGreeting.h"

std::string greeting = "Welcome to ENPM808X ";

bool update_greeting(beginner_tutorials::ChangeGreeting::Request  &req,
         beginner_tutorials::ChangeGreeting::Response &res) {
  res.old_greeting = greeting;
  greeting = req.new_greeting;
  ROS_ERROR_STREAM("The greeting was changed by service call");

  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::ServiceServer service = n.advertiseService("change_greeting",
    update_greeting);
  ROS_DEBUG_STREAM("Starting the change greeting service");

  int rate = 1;
  std::string arg = argv[1];

  if (argc == 2) {
    try {
      int arg_int = std::stoi(arg);
      if (arg_int > 100) {
        ROS_ERROR_STREAM("Publish rate is too high, using default.");
      } else {
        rate = arg_int;
      }
    } catch(std::invalid_argument const &ex) {
      ROS_FATAL_STREAM("Invalid argument. Please enter an integer");
      return 0;
    }
  } else if (argc > 2) {
    ROS_WARN_STREAM("Too many arguments given.");
  }

  ros::Rate loop_rate(rate);
  int count = 0;

  while (ros::ok()) {
    std_msgs::String msg;
    msg.data = greeting + std::to_string(count);
    ROS_INFO_STREAM(msg.data);
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}
