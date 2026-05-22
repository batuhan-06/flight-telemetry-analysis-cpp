#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <string>
#include "Event.h"


class Logger {
private:
    std::string fileName;
    std::ofstream file;

public:
    Logger(const std::string& fileName);

    void logEvent(const Event& event);

    ~Logger();
};

#endif