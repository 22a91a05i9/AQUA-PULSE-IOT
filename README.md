# AQUA-PULSE-IOT 💧

AQUA-PULSE is an intelligent, IoT-enabled water monitoring and automation system designed to track water parameters in real-time, optimize distribution, and prevent wastage. By leveraging low-power microcontrollers and cloud analytics, this system provides actionable insights into water quality, flow patterns, and consumption metrics.

---

## 📌 Project Overview & Context

Water scarcity and poor quality management are major modern challenges. AQUA-PULSE acts as a digital sentinel, providing end-to-end monitoring for residential, agricultural, or environmental applications (such as river health tracking). 

### Key Objectives:
* **Real-Time Analytics:** Continuous monitoring of vital water metrics (Flow rate, pH, Turbidity, Temperature, TDS).
* **Automated Control:** Smart relay mechanisms to shut down or trigger pumps based on water levels or safety thresholds.
* **Cloud Synchronization:** Pushing localized sensor logs to an IoT dashboard (e.g., Blynk, ThingSpeak, or a custom MQTT broker) for remote observation and anomaly alerts.

---

## 🚀 Key Features

* **Pulse-Based Flow Tracking:** Uses Hall-effect water flow sensors to measure consumption rates and pinpoint hidden pipeline leaks.
* **Water Quality Auditing:** Real-time analysis of contamination, acidity, and dissolved solids to ensure safety.
* **Intelligent Over-the-Air Alerts:** Instant notifications or SMS alerts generated when anomalous spikes or critical drops occur.
* **Eco-Friendly Design:** Optimized for low-power operation, making it ideal for solar-powered remote node setups.

---

## 🛠️ System Architecture & Hardware

```text
[Sensors: Flow, pH, TDS] ──► [MCU: ESP32 / ESP8266] ──► [Wi-Fi / LoRa] ──► [IoT Cloud Dashboard]
                                     │
                                     ▼
                             [Relay Module ──► Water Pump]

```

### Suggested Hardware Component List:

1. **Microcontroller:** ESP32 or NodeMCU ESP8266 (for native Wi-Fi stack capabilities).
2. **Flow Sensor:** YF-S201 Hall Effect Water Flow Sensor (translates water motion into pulse signals).
3. **Water Quality Suite:** Analog pH Sensor, Total Dissolved Solids (TDS) Meter, or Turbidity Sensor.
4. **Actuators:** 5V/12V Relay module to toggle water valves or electric pumps.
5. **Power Supply:** 5V Step-Down converter or Lithium-Ion battery setup with solar harvesting.

---

## 💻 Tech Stack

* **Firmware Language:** C++ / Arduino Framework
* **IoT Protocols:** MQTT, HTTP WebSockets
* **Cloud Platform Integration:** ThingSpeak / Blynk IoT / Node-RED / Home Assistant
* **Data Serialization:** JSON for lightweight packet delivery

---

## 📂 Repository Directory Structure

```text
├── Firmware/
│   ├── AquaPulse_Main.ino      # Primary Arduino microcontroller code
│   └── config.h                # Wi-Fi credentials and API token endpoints
├── Circuit/
│   └── schematics.png          # Pin mapping and hardware circuit diagram
├── Docs/
│   └── project_report.pdf      # Detailed technical analysis and data findings
└── README.md                   # Project index and deployment documentation

```

---

## 🛠️ Getting Started & Installation

To deploy the AQUA-PULSE firmware locally, follow these steps:

### Prerequisites

* Install the latest version of the [Arduino IDE](https://www.arduino.cc/en/software).
* Install the target board core (ESP32 by Espressif or ESP8266 community core) via the Boards Manager.
* Download required dependencies from the Library Manager:
* `PubSubClient` (for MQTT networking)
* `ArduinoJson` (for compiling data payloads)



### Setup Instructions

1. Clone this repository to your local directory:

```bash
   git clone [https://github.com/22a91a05i9/AQUA-PULSE-IOT.git](https://github.com/22a91a05i9/AQUA-PULSE-IOT.git)

```

2. Navigate into the `Firmware/` folder and open `AquaPulse_Main.ino`.
3. Update the `config.h` sheet with your local network configurations:

```cpp
   const char* ssid = "YOUR_WIFI_NAME";
   const char* password = "YOUR_WIFI_PASSWORD";
   const char* authToken = "YOUR_IOT_CLOUD_TOKEN";

```

4. Link your microcontroller via USB, select your board port, and click **Upload**.

---

## 👥 Contributors

This project exists thanks to the efforts of:

* **[Harisesha Sai](https://github.com/harisesha0205-pixel)** - Core Firmware & IoT Architecture.
* **[Lokanadham Jyoshnavi](https://github.com/22a91a05i9/)** - Mobile App Development & Documentation.
