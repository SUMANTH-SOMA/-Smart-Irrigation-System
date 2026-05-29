#include <DHT.h>
#define SOIL_MOISTURE_PIN A0
#define DHT_PIN 4
#define LED_PIN 5
DHT dht(DHT_PIN, DHT11);
void setup() {
pinMode(LED_PIN, OUTPUT);
dht.begin();
Serial.begin(9600); // Initialize serial communication
}
void loop() {
// Read soil moisture level
int soilMoisture = analogRead(SOIL_MOISTURE_PIN);
// Read temperature and humidity
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
// Print sensor readings to the serial monitor
Serial.print("Soil Moisture: ");
Serial.println(soilMoisture);
Serial.print("Temperature: ");
Serial.println(temperature);
Serial.print("Humidity: ");
Serial.println(humidity);
// Define moisture and temperature thresholds
int moistureThreshold = 500; // Adjust this value as needed
float temperatureThreshold = 25.0; // Adjust this value as needed
// Check conditions to activate the pump/valve
if (soilMoisture < moistureThreshold && temperature <
temperatureThreshold) {
digitalWrite(LED_PIN, HIGH); // Turn on the pump/valve
Serial.println("Pump/Valve is ON");
} else {
digitalWrite(LED_PIN, LOW); // Turn off the pump/valve
Serial.println("Pump/Valve is OFF");
}
delay(60000);
}
