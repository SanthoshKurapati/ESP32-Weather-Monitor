# ESP32 Weather Monitoring with Blynk

This project is an IoT-based temperature and humidity monitoring system. It uses an ESP32 microcontroller and a DHT22 sensor to collect environmental data and pushes it to a Blynk web dashboard in real-time. 

Currently, this project is simulated using Wokwi.

## Features
* **Real-time Monitoring:** Live temperature (°C) and humidity (%) tracking.
* **Data Visualization:** Uses Blynk's gauge and chart widgets to display historical and current data.
* **Non-blocking Timers:** Utilizes 'BlynkTimer' to ensure the main loop remains unblocked and the ESP32 maintains a stable connection to the cloud.

## Hardware / Simulation
* ESP32 Board
* DHT22 Temperature and Humidity Sensor
* [Wokwi Simulator]([https://wokwi.com/](https://wokwi.com/projects/458576952872819713))

## Software & Libraries
* Arduino IDE (or Wokwi Web Editor)
* 'BlynkSimpleEsp32'
* 'DHTesp'

## Dashboard Preview
Weather_Monitoring_Wokwi.png

## How to Run
1. Clone this repository.
2. Open the code in the Arduino IDE or copy it into a Wokwi ESP32 project.
3. Replace the 'BLYNK_AUTH_TOKEN' with your own token from the Blynk console.
4. Ensure your Blynk Datastreams are configured to 'V0' (Temperature) , 'V1' (Humidity) and 'V2' (Status).
5. Run the simulation or upload to your physical ESP32.
