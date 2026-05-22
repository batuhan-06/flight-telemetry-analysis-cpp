#include "TelemetryMonitor.h"
#include "Event.h"
#include <iostream>


TelemetryMonitor::TelemetryMonitor(const std::vector<TelemetryRecord>& records, const std::string& logFileName) : records(records), logger(logFileName) {}

void TelemetryMonitor::run() {
	if (records.empty()) {
		std::cout << "No records to monitor." << std::endl;
		return;
	}

	std::cout << "\n===== REAL-TIME TELEMETRY MONITORING =====\n";

	for (const auto& record : records) {
		checkRecord(record);
	}

	std::cout << "Monitoring completed. Events saved to log file." << std::endl;
}

void TelemetryMonitor::checkRecord(const TelemetryRecord& record) {
	if (record.getBattery() < 20) {
		Event event(
			record.getTimeSec(),
			"LOW_BATTERY",
			"CRITICAL",
			"Battery level dropped below 20%"
		);

		event.display();
		logger.logEvent(event);
	}

	if (record.getSpeed() > 35) {
		Event event(
			record.getTimeSec(),
			"HIGH_SPEED",
			"WARNING",
			"Speed exceeded safe threshold"
		);

		event.display();
		logger.logEvent(event);
	}

	if (record.getTemperature() > 50) {
		Event event(
			record.getTimeSec(),
			"HIGH_TEMPERATURE",
			"WARNING",
			"Temperature exceeded safe threshold"
		);

		event.display();
		logger.logEvent(event);
	}

	if (record.getGpsSatellites() < 6) {
		Event event(
			record.getTimeSec(),
			"WEAK_GPS_SIGNAL",
			"WARNING",
			"GPS signal dropped below safe level"
		);

		event.display();
		logger.logEvent(event);
	}
}