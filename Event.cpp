#include "Event.h"
#include <iostream>


Event::Event(int timeSec, std::string type, std::string severity, std::string message) :timeSec(timeSec), type(type), severity(severity), message(message) {}


int Event::getTimeSec() const {
	return timeSec;
}
std::string Event::getType() const {
	return type;
}
std::string Event::getSeverity() const {
	return severity;
}
std::string Event::getMessage() const {
	return message;
}

void Event::display() const {
	std::cout << "[" << severity << "] " << type << " at " << timeSec << "s --> " << message << std::endl;
}