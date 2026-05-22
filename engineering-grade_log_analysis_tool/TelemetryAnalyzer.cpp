#include "TelemetryAnalyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>


bool TelemetryAnalyzer::loadFromFile(const std::string& filename) {
	std::ifstream file(filename);

	if (!file) {
		std::cout << "File could not be opened." << std::endl;
		return false;
	}
	records.clear();

	std::string line;
	getline(file, line);

	while (getline(file, line)) {
		if (line.empty()) continue;

		std::stringstream ss(line);
		std::string timeStr, speedStr, altitudeStr, batteryStr, temperatureStr, gpsStr;

		getline(ss, timeStr, ',');
		getline(ss, speedStr, ',');
		getline(ss, altitudeStr, ',');
		getline(ss, batteryStr, ',');
		getline(ss, temperatureStr, ',');
		getline(ss, gpsStr);

		int timeSec = std::stoi(timeStr);
		double speed = std::stod(speedStr);
		double altitude = std::stod(altitudeStr);
		double battery = std::stod(batteryStr);
		double temperature = std::stod(temperatureStr);
		int gpsSatellites = std::stoi(gpsStr);

		records.emplace_back(timeSec, speed, altitude, battery, temperature, gpsSatellites);
	}

	file.close();
	return true;
}

void TelemetryAnalyzer::showAllRecords() const {
	if (records.empty()) {
		std::cout << "No telemetry records found." << std::endl;
		return;
	}
	for (const auto& record : records) {
		record.display();
	}
}

size_t TelemetryAnalyzer::getRecordCount() const {
	return records.size();
}

void TelemetryAnalyzer::showSummary() const {
	if (records.empty()) {
		std::cout << "No data to analyze." << std::endl;
		return;
	}

	double maxSpeed = records[0].getSpeed();
	double totalSpeed = 0;

	double maxAltitude = records[0].getAltitude();
	double totalAltitude = 0;

	double minBattery = records[0].getBattery();
	double maxTemperature = records[0].getTemperature();

	for (const auto& record : records) {
		double speed = record.getSpeed();
		double altitude = record.getAltitude();
		double battery = record.getBattery();
		double temperature = record.getTemperature();

		if (speed > maxSpeed) {
			maxSpeed = speed;
		}

		if (altitude > maxAltitude) {
			maxAltitude = altitude;
		}

		if (battery < minBattery) {
			minBattery = battery;
		}

		if (temperature > maxTemperature) {
			maxTemperature = temperature;
		}

		totalSpeed += speed;
		totalAltitude += altitude;
	}

	double avgSpeed = totalSpeed / records.size();
	double avgAltitude = totalAltitude / records.size();

	std::cout << "\n===== FLIGHT SUMMARY =====\n";
	std::cout << "Total Records        : " << records.size() << std::endl;
	std::cout << "Max Speed (m/s)      : " << maxSpeed << std::endl;
	std::cout << "Average Speed (m/s)  : " << avgSpeed << std::endl;
	std::cout << "Max Altitude (m)     : " << maxAltitude << std::endl;
	std::cout << "Average Altitude (m) : " << avgAltitude << std::endl;
	std::cout << "Minimum Battery (%)  : " << minBattery << std::endl;
	std::cout << "Max Temperature (C)  : " << maxTemperature << std::endl;
}

void TelemetryAnalyzer::detectAnomalies() const {
	if (records.empty()) {
		std::cout << "No data to analyze." << std::endl;
		return;
	}

	std::cout << "\n===== ANOMALY DETECTION =====\n";
	int anomalyCount = 0;

	for (size_t i = 0; i < records.size(); i++) {
		const auto& record = records[i];

		if (record.getBattery() < 20) {
			std::cout << "[LOW BATTERY] Time: " << record.getTimeSec() << "s | Battery: " << record.getBattery() << " %\n";
			anomalyCount++;
		}

		if (record.getSpeed() > 35) {
			std::cout << "[HIGH SPEED] Time: " << record.getTimeSec() << "s | Speed: " << record.getSpeed() << " m/s\n";
			anomalyCount++;
		}

		if (record.getTemperature() > 50) {
			std::cout << "[HIGH TEMPERATURE] Time: " << record.getTimeSec() << "s | Temperature: " << record.getTemperature() << " C\n";
			anomalyCount++;
		}

		if (record.getGpsSatellites() < 6) {
			std::cout << "[WEAK GPS SIGNAL] Time: " << record.getTimeSec() << "s | GPS Satellites: " << record.getGpsSatellites() << "\n";
			anomalyCount++;
		}

		if (i > 0) {
			double altitudeDiff = record.getAltitude() - records[i - 1].getAltitude();

			if (altitudeDiff < 0) {
				altitudeDiff = -altitudeDiff;
			}

			if (altitudeDiff > 30) {
				std::cout << "[ALTITUDE SPIKE] Time: " << record.getTimeSec() << "s | Altitude change: " << altitudeDiff << " m\n";
				anomalyCount++;
			}
		}
	}

	if (anomalyCount == 0) {
		std::cout << "No anomalies detected." << std::endl;
	}
	else {
		std::cout << "Total anomalies detected: " << anomalyCount << std::endl;
	}
}

void TelemetryAnalyzer::exportReport(const std::string& filename) const {
	std::ofstream report(filename);

	if (!report) {
		std::cout << "Report file could not be created." << std::endl;
		return;
	}

	if (records.empty()) {
		report << "No telemetry data available.\n";
		std::cout << "No data to export." << std::endl;
		return;
	}
	
	double maxSpeed = records[0].getSpeed();
	double totalSpeed = 0.0;

	double maxAltitude = records[0].getAltitude();
	double totalAltitude = 0.0;

	double minBattery = records[0].getBattery();
	double maxTemperature = records[0].getTemperature();

	for (const auto& record : records) {
		double speed = record.getSpeed();
		double altitude = record.getAltitude();
		double battery = record.getBattery();
		double temperature = record.getTemperature();

		if (speed > maxSpeed) {
			maxSpeed = speed;
		}

		if (altitude > maxAltitude) {
			maxAltitude = altitude;
		}

		if (battery < minBattery) {
			minBattery = battery;
		}

		if (temperature > maxTemperature) {
			maxTemperature = temperature;
		}

		totalSpeed += speed;
		totalAltitude += altitude;
	}

	double avgSpeed = totalSpeed / records.size();
	double avgAltitude = totalAltitude / records.size();

	report << "===== FLIGHT TELEMETRY ANALYSIS REPORT =====\n\n";
	report << "Total Records       : " << records.size() << "\n";
	report << "Max Speed (m/s)     : " << maxSpeed << "\n";
	report << "Average Speed (m/s) : " << avgSpeed << "\n";
	report << "Max Altitude (m)    : " << maxAltitude << "\n";
	report << "Average Altitude (m): " << avgAltitude << "\n";
	report << "Minimum Battery (%) : " << minBattery << "\n";
	report << "Max Temperature (C) : " << maxTemperature << "\n\n";

	report << "===== DETECTED ANOMALIES =====\n";
	int anomalyCount = 0;

	for (size_t i = 0; i < records.size(); i++) {
		const auto& record = records[i];

		if (record.getBattery() < 20) {
			report << "[LOW BATTERY] Time: " << record.getTimeSec() << "s | Battery: " << record.getBattery() << " %\n";
			anomalyCount++;
		}

		if (record.getSpeed() > 35) {
			report << "[HIGH SPEED] Time: " << record.getTimeSec() << "s | Speed: " << record.getSpeed() << " m/s\n";
			anomalyCount++;
		}

		if (record.getTemperature() > 50) {
			report << "[HIGH TEMPERATURE] Time: " << record.getTimeSec() << "s | Temperature: " << record.getTemperature() << " C\n";
			anomalyCount++;
		}

		if (record.getGpsSatellites() < 6) {
			report << "[WEAK GPS SIGNAL] Time: " << record.getTimeSec() << "s | GPS Satellites: " << record.getGpsSatellites() << "\n";
			anomalyCount++;
		}

		if (i > 0) {
			double altitudeDiff = record.getAltitude() - records[i - 1].getAltitude();

			if (altitudeDiff < 0) {
				altitudeDiff = -altitudeDiff;
			}

			if (altitudeDiff > 30) {
				report << "[ALTITUDE SPIKE] Time: " << record.getTimeSec() << "s | Altitude change: " << altitudeDiff << " m\n";
				anomalyCount++;
			}
		}
	}

	if (anomalyCount == 0) {
		report << "No anomalies detected." << std::endl;
	}
	else {
		report << "\nTotal anomalies detected: " << anomalyCount << std::endl;
	}

	report.close();
	std::cout << "Analysis report exported successfully." << std::endl;
}

const std::vector<TelemetryRecord>& TelemetryAnalyzer::getRecords() const {
	return records;
}