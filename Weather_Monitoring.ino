// Blynk configuration (MUST be at the very top)
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Weather Monitoring"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

// Enable debug prints to the Serial Monitor
#define BLYNK_PRINT Serial 

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHTesp.h"

// Wokwi's free simulation WiFi credentials
char ssid[] = "Wifi-Name";
char pass[] = "Wifi-Password";

// DHT sensor setup
const int DHT_PIN = 15;
DHTesp dhtSensor;

// Create a Blynk Timer to handle intervals without blocking the loop
BlynkTimer timer;

// This function reads the sensor and pushes the data to Blynk
void sendSensorData() {
  // Read temperature and humidity using the DHTesp library
  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  // Check if the reading was successful
  if (dhtSensor.getStatus() != 0) {
    Serial.println("Error reading from DHT sensor!");
    return;
  }

  // Print to the Serial Monitor for local debugging
  Serial.print("Temp: ");
  Serial.print(data.temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(data.humidity);
  Serial.println(" %");

  // Push the data to Blynk Virtual Pins
  // Note: Ensure your Blynk Datastreams match these virtual pins!
  Blynk.virtualWrite(V0, data.temperature); 
  Blynk.virtualWrite(V1, data.humidity);    
}

void setup() {
  Serial.begin(115200);
  
  // Initialize the DHT sensor
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  // Connect to the Wokwi WiFi and the Blynk Cloud
  Serial.println("Connecting to Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Tell the timer to run the sendSensorData function every 2000 milliseconds (2 seconds)
  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  // Keep the Blynk connection alive
  Blynk.run();
  
  // Keep the timer running
  timer.run();
}
