#ifndef TELEMETRYMONITOR_H
#define TELEMETRYMONITOR_H
#include <vector>
#include <string>
#include "TelemetryRecord.h"
#include "Logger.h"


class TelemetryMonitor {
private:
	std::vector<TelemetryRecord> records;
	Logger logger;

	void checkRecord(const TelemetryRecord& record);
public:
	TelemetryMonitor(const std::vector<TelemetryRecord>& records, const std::string& logFileName);
	void run();
};

#endif