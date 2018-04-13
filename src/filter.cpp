#include "ros/ros.h"
#include "std_msgs/String.h"
#include <stdio.h>
#include <termios.h>

ros::Publisher chatter_pub;

int main(int argc, char **argv)
{

	ros::init(argc, argv, "filter");
	ros::NodeHandle m;
	chatter_pub = m.advertise<std_msgs::String>("chat2", 1000); // Sincronizzazione con la chat2.
	ros::Rate loop_rate(10);
	while ( ros::ok() )
	{
		std_msgs::String msg;
	   	std::stringstream ss;
		std::cout << "Menú \nPremi n per stampare il nome\nPremi e per stampare l'etá\nPremi c per stampare il corso\nPremi a per stampare tutte le informazioni\n";
		char carattere;
		std::cin >> carattere;
		ss << carattere;
	    	msg.data = ss.str();
		if( carattere == 'a' || carattere == 'e' || carattere == 'n' || carattere == 'c' )
		{
			std::cout << "Hai premuto il tasto " << carattere << "\n\n\n";
			chatter_pub.publish(msg); // Invio del carattere.
		}
		else
		{
			std::cout << "Carattere inserito non valido!\n\n\n";		
		}
	    	ros::spinOnce();
	    	loop_rate.sleep();
  	}
	return 0;
}
