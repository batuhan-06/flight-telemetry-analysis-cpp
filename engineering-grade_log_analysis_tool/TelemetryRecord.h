#ifndef TELEMETRYRECORD_H
#define TELEMETRYRECORD_H


class TelemetryRecord {
private:
	int timeSec;
	double speed;
	double altitude;
	double battery;
	double temperature;
	int gpsSatellites;

public:
	TelemetryRecord(int timeSec = 0, double speed = 0.0, double altitude = 0.0, double battery = 0.0, double temperature = 0.0, int gpsSatellites = 0);

	int getTimeSec() const;
	double getSpeed() const;
	double getAltitude() const;
	double getBattery() const;
	double getTemperature() const;
	int getGpsSatellites() const;

	void display() const;

};

#endif	