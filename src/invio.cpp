#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "invio"); //Dichiarazione nodo.
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
	ros::Rate loop_rate(10);
	while ( ros::ok() ) // Ciclo infinito.
	{
	    	std_msgs::String msg;
	    	std::stringstream ss;
	    	ss << "Eros 20 Bioinformatica"; // Creazione della stringa da inviare.
	    	msg.data = ss.str();
		std::cout << "Invio del messaggio ...\n";
	    	chatter_pub.publish(msg); // Invio.
	    	ros::spinOnce();
	    	loop_rate.sleep();
  	}
  	return 0;
}
