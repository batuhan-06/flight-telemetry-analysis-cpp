#include <iostream>
#include "TelemetryAnalyzer.h"
#include "TelemetryMonitor.h"

int main() {
	TelemetryAnalyzer analyzer;

	if (!analyzer.loadFromFile("telemetry_data.csv")) {
		std::cout << "Failed to load telemetry data." << std::endl;
		return 1;
	}

	std::cout << "Telemetry data loaded successfully." << std::endl;
	std::cout << "Total records loaded: " << analyzer.getRecordCount() << std::endl;

	analyzer.showAllRecords();
	analyzer.showSummary();
	analyzer.detectAnomalies();
	analyzer.exportReport("analysis_report.txt");

	TelemetryMonitor monitor(analyzer.getRecords(), "system_logs.txt");
	monitor.run();

	std::cout << "\nProgram finished successfully." << std::endl;

	return 0;
}