#include "ros/ros.h"
#include "std_msgs/String.h"
#include <stdio.h>
#include <termios.h>

ros::Publisher chatter_pub;
//int carattere;

//void Cambio( void )
//{
//	while(1)
//	{
//		scanf("%c", &carattere );
//	}
//}

//void chatterCallback(const std_msgs::String::ConstPtr& msg)
//{
  //	ROS_INFO("I heard: [%s]", msg->data.c_str());
//
//	std_msgs::String msg2;
//
//	std::stringstream ss;
	//int age = 20;
	//std::string name = "Eros ";
	//std::string corso = " cdl in Bioinformatica";
	//ss << "Eros secondo invio";
	//ss << name << age << corso;

//	carattere = getch();
//	if( carattere == 'a' )
//		printf("Tutto bene \n");

//	msg2.data = ss.str();

//	ROS_INFO("%s", msg2.data.c_str());

//	chatter_pub.publish(msg2);
//}


int main(int argc, char **argv)
{
	
  	ros::init(argc, argv, "filter");
	//ros::NodeHandle n;
	//ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

	ros::NodeHandle m;
	chatter_pub = m.advertise<std_msgs::String>("chat2", 1000);
	//int count = 0;
	ros::Rate loop_rate(10);
	while ( ros::ok() )
	{

	    	std_msgs::String msg;

	    	std::stringstream ss;
		//int age = 20;
		//std::string name = "Eros ";
		//std::string corso = " cdl in Bioinformatica";
	    	//ss << "Eros 20 cdl Bioinformatica";
		//ss << name << age << corso;
		std::cout << " Menú \nPremi n per stampare il nome\nPremi e per stampare l'etá\nPremi c per stampare il corso\nPremi a per stampare tutte le informazioni\n";
		char carattere;
		std::cin >> carattere;
		ss << carattere;
	    	msg.data = ss.str();

	    	ROS_INFO("Hai premuto: %s\n", msg.data.c_str());

	    	chatter_pub.publish(msg);
	
	    	ros::spinOnce();

	    	loop_rate.sleep();

	    	//++count;
  	}
	return 0;
}
