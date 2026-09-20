# Flight Telemetry Monitoring & Fault Detection System (C++)

## Project Preview

This project evolved from a telemetry analysis tool into a modular monitoring system capable of anomaly detection, event generation, and persistent logging.

Instead of only parsing telemetry data, the system simulates monitoring behavior used in high-reliability environments by detecting abnormal conditions and generating alerts.

---

## Overview

A console-based C++ monitoring system that:

- Parses flight telemetry data from CSV files
- Computes mission statistics
- Detects anomalies and unsafe conditions
- Generates events with severity levels
- Logs critical events into persistent log files
- Exports analysis reports

The project follows a modular architecture inspired by monitoring systems used in aerospace and reliability-focused environments.

---

## Features

### Telemetry Processing

* Parse telemetry data from CSV files
* Display all telemetry records
* Compute flight statistics:

  * Maximum speed
  * Average speed
  * Maximum altitude
  * Average altitude
  * Minimum battery level
  * Maximum temperature

---

### Anomaly Detection

Detects abnormal conditions such as:

* Low battery
* High speed
* High temperature
* Weak GPS signal
* Sudden altitude changes

---

### Monitoring System (V2 Upgrade)

Added monitoring architecture with:

* Real-time telemetry monitoring simulation
* Event-driven alert generation
* Persistent logging system (`system_logs.txt`)
* Severity-based alerts:

```text
WARNING
CRITICAL
```

* Modular monitoring architecture
* Fault detection workflow

---

### Report Generation

Exports analysis results into:

```text
analysis_report.txt
```

---

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* STL (`vector`, `string`)
* File handling (`ifstream`, `ofstream`)
* String parsing (`stringstream`)
* Event-driven architecture
* Logging systems
* Monitoring systems
* Fault detection logic

---

## Project Structure

```text
FlightTelemetryMonitoringSystem/

│
├── TelemetryRecord.h
├── TelemetryRecord.cpp
│
├── TelemetryAnalyzer.h
├── TelemetryAnalyzer.cpp
│
├── Event.h
├── Event.cpp
│
├── Logger.h
├── Logger.cpp
│
├── TelemetryMonitor.h
├── TelemetryMonitor.cpp
│
├── main.cpp
│
├── telemetry_data.csv
├── analysis_report.txt
├── system_logs.txt
```

---

## Example Data Format

```csv
time_sec,speed_mps,altitude_m,battery_percent,temperature_c,gps_satellites

1,12.5,105.0,98,32.5,10
2,13.8,110.0,96,33.1,10
3,15.2,118.0,94,34.0,9
```

---

## Example Output

### Flight Summary

```text
===== FLIGHT SUMMARY =====

Total Records: 8
Max Speed: 37.2
Average Speed: 20.46
Max Altitude: 198
Minimum Battery: 15
```

---

### Monitoring Output

```text
===== REAL-TIME TELEMETRY MONITORING =====

[WARNING] HIGH_SPEED at 6s
[CRITICAL] LOW_BATTERY at 7s
[WARNING] HIGH_TEMPERATURE at 7s
[WARNING] WEAK_GPS_SIGNAL at 8s
```

---

### Example Log File

```text
[WARNING] HIGH_SPEED at 6s --> Speed exceeded safe threshold

[CRITICAL] LOW_BATTERY at 7s --> Battery level dropped below 20%
```

---

## Engineering Concepts Practiced

This project helped strengthen skills in:

* Modular software design
* Event-based systems
* Monitoring architectures
* Fault detection logic
* File handling
* Data analysis
* Object-oriented design
* Reliability-focused programming

---

## Future Improvements (V3)

Planned upgrades:

* Timestamp-based logging
* Multithreading support
* Adaptive anomaly thresholds
* Live sensor integration
* Real-time streaming telemetry
* Visualization dashboard

---

## Author
Batuhan