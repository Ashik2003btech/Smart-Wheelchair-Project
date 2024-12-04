# Arduino Joystick-Controlled Motor and Heart Rate Monitoring System

## Description

This project demonstrates two functionalities:
1. **Joystick-Controlled Motor Movement:** Control two DC motors using a joystick for directional navigation.
2. **Heart Rate Monitoring with OLED Display:** Measure heart rate and SpO2 using a MAX30105 sensor and display the data on an SSD1306 OLED screen.

---

## Features

1. **Joystick-Based Motor Control**:
   - X-axis: Forward and backward movement.
   - Y-axis: Left and right movement.
   - Motor speeds are dynamically adjusted based on joystick input.

2. **Heart Rate Monitoring**:
   - Measures heart rate and SpO2 using the MAX30105 sensor.
   - Displays real-time IR and Red light values on the OLED screen.

---

## Requirements

### Hardware Components:
- Arduino (UNO, Nano, Mega, or similar)
- Joystick module
- 2 DC motors
- L298N Motor Driver Module
- MAX30105 Pulse Oximeter and Heart Rate Sensor
- SSD1306 OLED Display
- Connecting wires
- Power supply (Battery or USB)

### Libraries:
1. [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
2. [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
3. [SparkFun MAX3010x Sensor Library](https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library)

---

## Circuit Connections

### Motor Control:
- **Joystick Module**:
  - `VCC` → Arduino `5V`
  - `GND` → Arduino `GND`
  - `VRx` → Arduino `A1` (X-axis)
  - `VRy` → Arduino `A0` (Y-axis)
- **L298N Motor Driver**:
  - `enA` → Arduino `D5`
  - `in1` → Arduino `D6`
  - `in2` → Arduino `D7`
  - `in3` → Arduino `D8`
  - `in4` → Arduino `D9`
  - `enB` → Arduino `D10`

### Heart Rate Monitoring:
- **MAX30105**:
  - `SCL` → Arduino `A5`
  - `SDA` → Arduino `A4`
  - `VCC` → Arduino `3.3V`
  - `GND` → Arduino `GND`
- **SSD1306 OLED**:
  - `SCL` → Arduino `A5`
  - `SDA` → Arduino `A4`
  - `VCC` → Arduino `3.3V`
  - `GND` → Arduino `GND`

---

## Usage

### 1. Joystick Motor Control:
   - Push the joystick forward or backward to control the motor's forward or backward movement.
   - Push the joystick left or right to make the motors turn accordingly.
   - Release the joystick to stop the motors.

### 2. Heart Rate Monitoring:
   - Start the Arduino to initialize the sensor.
   - The OLED display will show real-time IR and Red light values from the MAX30105 sensor.
   - The data helps in determining the heart rate and SpO2 values.

---

## Code Explanation

- **Motor Control Functions**:
  - `forword()`: Moves motors forward.
  - `backword()`: Moves motors backward.
  - `turnRight()`: Turns the motors to the right.
  - `turnLeft()`: Turns the motors to the left.
  - `Stop()`: Stops the motors.

- **Heart Rate Monitoring**:
  - Uses the MAX30105 sensor to read IR and Red light values.
  - Displays values on the OLED screen for easy monitoring.

---

## Setup Instructions

1. Install the required libraries via the Arduino IDE Library Manager.
2. Connect the hardware components as per the circuit diagram.
3. Upload the Arduino code to the board.
4. Power the Arduino and test the functionality.

---

## Future Improvements

- Integrate SpO2 calculation logic for real-time display.
- Add motor speed control with finer resolution.
- Enhance joystick sensitivity for smoother control.

---

## Author

**Mohamed Ashik**  
Student, B.Tech Electronics and Communication Engineering (ECE)  
Vellore Institute of Technology, Chennai  

---

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute the code as needed.
