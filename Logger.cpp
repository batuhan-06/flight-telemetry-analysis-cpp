#include "Logger.h"
#include <iostream>


Logger::Logger(const std::string& fileName) :fileName(fileName) {
	file.open(fileName);

	if (!file) {
		std::cout << "Log file could not be opened." << std::endl;
	}
}

void Logger::logEvent(const Event& event) {
	if (file.is_open()) {
		file << "[" << event.getSeverity() << "] " << event.getType() << " at " << event.getTimeSec() << "s --> " << event.getMessage() << std::endl;
	}
}

Logger::~Logger() {
	if (file.is_open()) {
		file.close();
	}
}