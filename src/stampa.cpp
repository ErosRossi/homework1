#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

char carattere ='a';

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  	ROS_INFO("I heard: [%s]", msg->data.c_str());
	int age;
	std::string nome;
	std::string corso;
	//std::string s = msg->data.c_str();
	std::stringstream ss;
	ss << msg->data.c_str();
	ss >> nome >> age >> corso;
	std::cout << carattere << "\n";
	switch( carattere )
	{
		case 'a':
		std::cout << nome << " " << age << " " << corso << "\n";
		break;

		case 'e':
		std::cout << age << "\n";
		break;

		case 'n':
		std::cout << nome << "\n";
		break;

		case 'c':
		std::cout << corso << "\n";
		break;
	}
}

void chatterCallback2(const std_msgs::String::ConstPtr& msg)
{
  	ROS_INFO("Inserito il carattere: [%s]", msg->data.c_str());
	std::stringstream ss;
	ss << msg->data.c_str();
	ss >> carattere;
}


int main(int argc, char **argv)
{
  
  	ros::init(argc, argv, "stampa");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

	ros::NodeHandle m;
	ros::Subscriber sub2 = m.subscribe("chat2", 1000, chatterCallback2);

	ros::spin();
	return 0;
}
