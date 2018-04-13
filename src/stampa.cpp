#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

char carattere ='z'; // Inizializzo il carattere a z per far attendere la stampa.

void chatterCallback(const std_msgs::String::ConstPtr& msg) // Callback di gestione della stampa.
{
	int age;
	std::string nome;
	std::string corso;
	std::stringstream ss;
	ss << msg->data.c_str();
	ss >> nome >> age >> corso; // divido il messaggio nelle sue 3 parti.
	switch( carattere ) // decido quale porzione del messaggio stampare.
	{
		case 'a':
		std::cout << "Stampo la stringa completa: "<< nome << " " << age << " " << corso << "\n";
		break;

		case 'e':
		std::cout << "Stampo l'etá: " << age << "\n";
		break;

		case 'n':
		std::cout << "Stampo il nome: " << nome << "\n";
		break;

		case 'c':
		std::cout << "Stampo il cdl: " << corso << "\n";
		break;

		case 'z':
		break;

	}
}

void chatterCallback2(const std_msgs::String::ConstPtr& msg) // Callback che gestisce la ricezione del carattere per la decisione della porzione da stampare.
{
  	ROS_INFO("Ricevuto il carattere: [%s]", msg->data.c_str());
	std::stringstream ss;
	ss << msg->data.c_str();
	ss >> carattere;
}


int main(int argc, char **argv)
{
  	ros::init(argc, argv, "stampa");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback); // Sintonizzazione con il nodo che invia la stringa.

	ros::NodeHandle m;
	ros::Subscriber sub2 = m.subscribe("chat2", 1000, chatterCallback2); // Sintonizzazione con il nodo che invia il carattere.

	ros::spin();
	return 0;
}
