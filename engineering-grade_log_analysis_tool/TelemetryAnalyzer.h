#ifndef TELEMETRYANALYZER_H
#define TELEMETRYANALYZER_H
#include <vector>
#include <string>
#include "TelemetryRecord.h"


class TelemetryAnalyzer {
private:
	// Stores all telemetry records loaded from file
	std::vector<TelemetryRecord> records;

public:
	// Loads telemetry data from CSV file
	bool loadFromFile(const std::string& filename);

	void showAllRecords() const;
	void showSummary() const;
	void detectAnomalies() const;
	void exportReport(const std::string& filename) const;

	// Returns number of records
	size_t getRecordCount() const;

	const std::vector<TelemetryRecord>& getRecords() const;
};

#endif