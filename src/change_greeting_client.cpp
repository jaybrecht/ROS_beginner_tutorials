// "Copyright [2020] Justin Albrecht"

#include <string>
#include "ros/ros.h"
#include "beginner_tutorials/ChangeGreeting.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "change_greeting_client");
  if (argc < 2) {
    ROS_ERROR_STREAM("usage: change_greeting_client <New Greeting>");
    return 1;
  }

  std::string new_greeting;

  for (int i = 1; i < argc; i++) {
    new_greeting += argv[i];
    new_greeting += " ";
  }

  ros::NodeHandle n;
  ros::ServiceClient client =
    n.serviceClient<beginner_tutorials::ChangeGreeting>("change_greeting");

  beginner_tutorials::ChangeGreeting srv;
  srv.request.new_greeting = new_greeting;

  if (client.call(srv)) {
    ROS_INFO_STREAM("The greeting has been changed from " <<
      "\"" << srv.response.old_greeting
      << "\" to \"" << srv.request.new_greeting << "\"");
  } else {
    ROS_ERROR_STREAM("Failed to call service");
    return 1;
  }

  return 0;
}
