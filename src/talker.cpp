#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeGreeting.h"

std::string greeting = "Welcome to ENPM808X ";

bool update_greeting(beginner_tutorials::ChangeGreeting::Request  &req,
         beginner_tutorials::ChangeGreeting::Response &res) {
  res.old_greeting = greeting;
  greeting = req.new_greeting;

  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::ServiceServer service = n.advertiseService("change_greeting", update_greeting);

  ros::Rate loop_rate(10);
  
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
