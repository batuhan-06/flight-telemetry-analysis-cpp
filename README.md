# Flight Telemetry Analysis & Anomaly Detection Tool (C++)

## Project Preview

This project analyzes telemetry data, detects anomalies, and generates a structured report.

## Overview

A console-based C++ tool that parses flight telemetry data from a CSV file, computes mission statistics, detects anomalies, and exports analysis reports.

## Features

* Parse telemetry data from CSV files
* Display all telemetry records
* Compute flight statistics:

  * Maximum speed
  * Average speed
  * Maximum altitude
  * Average altitude
  * Minimum battery level
  * Maximum temperature
* Detect anomalies:

  * Low battery
  * High speed
  * High temperature
  * Weak GPS signal
  * Sudden altitude changes
* Export analysis results to a report file

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* STL (vector, string)
* File handling (ifstream, ofstream)
* String parsing (stringstream)

## Project Structure

```
TelemetryAnalyzer/
│
├── TelemetryRecord.h
├── TelemetryRecord.cpp
├── TelemetryAnalyzer.h
├── TelemetryAnalyzer.cpp
├── main.cpp
├── telemetry_data.csv
```

## Example Data Format

```
time_sec,speed_mps,altitude_m,battery_percent,temperature_c,gps_satellites
1,12.5,105.0,98,32.5,10
2,13.8,110.0,96,33.1,10
```

## Example Output

```
===== FLIGHT SUMMARY =====
Total Records: 8
Max Speed (m/s): 37.2

===== ANOMALY DETECTION =====
[HIGH SPEED] ...
[LOW BATTERY] ...
```

## Future Improvements

* Real-time telemetry processing
* Data visualization (charts/graphs)
* Integration with live sensor data
* Advanced anomaly detection algorithms

## Author
Batuhan
