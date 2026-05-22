#include "TelemetryRecord.h"
#include <iostream>


TelemetryRecord::TelemetryRecord(int timeSec, double speed, double altitude, double battery, double temperature, int gpsSatellites) : timeSec(timeSec), speed(speed), altitude(altitude), battery(battery), temperature(temperature), gpsSatellites(gpsSatellites) {}


int TelemetryRecord::getTimeSec() const {
	return timeSec;
}
double TelemetryRecord::getSpeed() const {
	return speed;
}
double TelemetryRecord::getAltitude() const {
	return altitude;
}
double TelemetryRecord::getBattery() const {
	return battery;
}
double TelemetryRecord::getTemperature() const {
	return temperature;
}
int TelemetryRecord::getGpsSatellites() const {
	return gpsSatellites;
}


void TelemetryRecord::display() const{
	std::cout << "Time (s): " << timeSec << std::endl;
	std::cout << "Speed (m/s): " << speed << std::endl;
	std::cout << "Altitude (m): " << altitude << std::endl;
	std::cout << "Battery (%): " << battery << std::endl;
	std::cout << "Temperature (C): " << temperature << std::endl;
	std::cout << "Gps Satellites: " << gpsSatellites << std::endl;
	std::cout << "--------------------------" << std::endl;
}