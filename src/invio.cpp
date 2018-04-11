#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "invio");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
	ros::Rate loop_rate(10);
	while ( ros::ok() )
	{

	    	std_msgs::String msg;
	    	std::stringstream ss;
	    	ss << "Eros 20 cdl Bioinformatica";
	    	msg.data = ss.str();
		std::cout << "Invio del messaggio ...\n";
	    	chatter_pub.publish(msg);
	    	ros::spinOnce();
	    	loop_rate.sleep();
  	}
  	return 0;
}
