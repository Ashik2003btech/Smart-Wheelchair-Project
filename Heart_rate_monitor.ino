#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MAX30105.h>
#include <heartRate.h>
// Pin definitions for I2C
#define SDA_PIN A4 // Adjust based on your board (e.g., GPIO21 for ESP32)
#define SCL_PIN A5 // Adjust based on your board (e.g., GPIO22 for ESP32)

// OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Initialize the OLED display
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

// Initialize the MAX30105 sensor
MAX30105 particleSensor;

// Variables for heart rate and SpO2
int beatAvg = 0;

void setup() {
  // Set up I2C pins
  Wire.begin(SDA_PIN, SCL_PIN);
  
  // Initialize Serial communication
  Serial.begin(115200);
  while (!Serial); // Wait for Serial monitor to connect
  
  // Initialize OLED display
  if (!oled.begin(SSD1306_I2C_ADDRESS, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for (;;); // Halt execution if OLED initialization fails
  }
  oled.clearDisplay();
  oled.display();
  // Initialize MAX30105 sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
    Serial.println("MAX30105 was not found. Please check wiring/power.");
    for (;;); // Halt execution if MAX30105 initialization fails
  }
  // Configure the MAX30105 sensor
  particleSensor.setup(); // Default settings
  particleSensor.setPulseAmplitudeRed(0x0A); // Red LED
  particleSensor.setPulseAmplitudeIR(0x0A); // IR LED
}
void loop() {
  // Read IR and Red values from the sensor
  long irValue = particleSensor.getIR();
  long redValue = particleSensor.getRed();
  
  // Print values to Serial Monitor (optional)
  Serial.print("IR: ");
  Serial.print(irValue);
  Serial.print("\tRed: ");
  Serial.println(redValue);
  
  // Display data on OLED screen
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  
  oled.setCursor(0, 0);
  oled.print("IR: ");
  oled.println(irValue);
  
  oled.setCursor(0, 10);
  oled.print("Red: ");
  oled.println(redValue);
  
  oled.display();
  
  delay(500); // Delay for readability
}