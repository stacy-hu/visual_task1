#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char * argv[])
{
    ros::init(argc, argv, "talker");

    ros::NodeHandle n;
    rmw_qos_profile_t custom_qos_profile = rmw_qos_profile_default;
    custom_qos_profile.depth = 7;

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);

    auto msg = std::make_shared<std_msgs::msg::String>();

    while (ros::ok())
    {
		for (i = 0; i < 10; i++)
			msg->data = "Value: " + std::to_string(i);
			chatter_pub.publish(msg);
			ros::spinOnce();
			loop_rate.sleep();
    }

    return 0;
}