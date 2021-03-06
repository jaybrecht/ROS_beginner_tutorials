# ROS Beginner Tutorials

## Introduction

This repository contains two ROS nodes, a publisher and subscriber. The publisher node contained in talker.cpp publishes a custom message to the "chatter" topic. The subscriber node contained in listener.cpp subsribes to that topic and outputs to the console what it "hears". 

## Dependencies 

This repository assumes you are running Ubuntu 18.04 with ROS Melodic installed. To install ROS Melodic see [here](http://wiki.ros.org/melodic/Installation/Ubuntu).

## Instructions for Running the Program

To run this repository you must first create a catkin workspace. The following directions will apply for a catkin_ws in your home directory. 

```
source /opt/ros/melodic/setup.bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
```

After you have created a catkin workspace you can clone this repository into the src directory

```
cd ~/catkin_ws/src
git clone https://github.com/jaybrecht/ROS_beginner_tutorials beginner_tutorials
```

Then you need to build the catkin_ws

```
cd ~/catkin_ws/
catkin_make
```

To run the nodes you will need three terminals. In the first type:

```
source /opt/ros/melodic/setup.bash
roscore
```

In the second terminal type below to run the talker node

```
source /opt/ros/melodic/setup.bash
source ~/catkin_ws/devel/setup.bash
rosrun beginner_tutorials talker
```

If desired the rate at which new messages are published can be changed with a command line argument. The rate will be how many times a message is published per second. The default is 10.

```
rosrun beginner_tutorials talker <rate>
```


In the second terminal type below to run the listener node:

```
source /opt/ros/melodic/setup.bash
source ~/catkin_ws/devel/setup.bash
rosrun beginner_tutorials listener
```

## Changing the Greeting

The talker node inlcudes a service that allows for the greeting to be changed. To call this service type below in a separate terminal. (Note: the talker nodes needs to be running before this service can be called)

```
source /opt/ros/melodic/setup.bash
source ~/catkin_ws/devel/setup.bash
rosrun beginner_tutorials change_greeting <New Greeting>
```

## Starting with Launch file 

Both nodes can be started with a launch file:

```
source /opt/ros/melodic/setup.bash
source ~/catkin_ws/devel/setup.bash
roslaunch beginner_tutorials tutorial.launch
```

You can change the publishing rate by modifying the pub_rate argument

```
roslaunch beginner_tutorials tutorial.launch pub_rate:=1
```