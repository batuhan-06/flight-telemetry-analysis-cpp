#ifndef EVENT_H
#define EVENT_H
#include <string>


class Event {
private:
	int timeSec;
	std::string type;
	std::string severity;
	std::string message;

public:
	Event(int timeSec = 0, std::string type = "", std::string severity = "", std::string message = "");

	int getTimeSec() const;
	std::string getType() const;
	std::string getSeverity() const;
	std::string getMessage() const;

	void display() const;

};

#endif