# a VERY SMPLE Proximity Warning System

## Overview
The **Proximity Warning System** is an Arduino-based project that uses an **HC-SR04 ultrasonic sensor** to detect objects and provide **visual and auditory warnings** using LEDs and a buzzer. A **servo motor** continuously moves the sensor to scan the environment, and an LCD display shows the measured distance in real-time.

## Features
✅ **Ultrasonic Distance Measurement** – Detects objects using an **HC-SR04 sensor**.  
✅ **LED Warning System** – A **Yellow LED (Caution)** and **Red LED (Danger)** indicate proximity.  
✅ **Buzzer Alert** – Beeps when an object is too close.  
✅ **Servo Motor Scanning** – Rotates the sensor from **0° to 180°** and back.  
✅ **LCD Display** – Shows the measured distance in real-time.  
✅ **Pause Function** – Allows stopping and resuming the system with a button press.  
✅ **Serial Monitor Commands** – Pause (`P`) and Resume (`R`) via the Serial Monitor.

## Components Used
- **Arduino Uno R3**
- **HC-SR04 Ultrasonic Sensor**
- **SG90 Servo Motor**
- **16x2 LCD Display (Parallel Connection)**
- **Buzzer**
- **Red LED (Danger Zone Indicator)**
- **Yellow LED (Caution Zone Indicator)**
- **Push Button (Pause/Resume System)**
- **220Ω Resistors**
- **Breadboard & Jumper Wires**

## Wiring Diagram
| **Component**   | **Arduino Pin**  |
|----------------|-----------------|
| **HC-SR04 Trig** | **10**  |
| **HC-SR04 Echo** | **11**  |
| **Servo Motor Signal** | **12**  |
| **Buzzer** | **9**  |
| **Red LED** | **13**  |
| **Yellow LED** | **2**  |
| **Pause Button** | **4**  |
| **LCD RS, E, D4, D5, D6, D7** | **7, 6, 5, 4, 3, 8**  |

## Installation
1. **Clone the repository:**
   ```sh
   git clone https://github.com/yourusername/proximity-warning-system.git
   cd proximity-warning-system
   ```
2. **Open the Arduino Sketch (`.ino` file) in Arduino IDE.**
3. **Install required libraries:**
   - `LiquidCrystal.h` (for LCD display)
   - `Servo.h` (for servo control)
4. **Connect the components following the wiring diagram.**
5. **Upload the code to your Arduino Uno.**
6. **Open the Serial Monitor (`Ctrl + Shift + M`) to monitor distance readings.**

## How It Works
1. The **servo motor** moves the ultrasonic sensor between **0° and 180°**.
2. The **HC-SR04 sensor** measures distance every **300ms**.
3. The **LCD displays the current distance**.
4. The **LED warning system activates**:
   - **Distance < 10 cm** → Red LED ON + Buzzer Alert ⚠️
   - **Distance 10-20 cm** → Yellow LED ON ⚠️
   - **Distance > 20 cm** → LEDs & Buzzer OFF ✅
5. **Pause the system**:
   - Press the **pause button** → System stops & LCD shows "System Paused"
   - Press again → Resumes operation.
   - OR use Serial Monitor: Send `P` (Pause) / `R` (Resume).

## Usage
- **Detects nearby objects and provides warnings** for obstacle avoidance.
- **Can be used as a simple security system** to detect intruders.
- **Great for robotics and automation projects** that need distance measurement.

## Future Improvements
🔹 Add an **OLED/TFT screen** for graphical radar display.  
🔹 Implement **Bluetooth/Wi-Fi** to send warnings to a mobile app.  
🔹 Upgrade to a **stepper motor** for smoother scanning.  
🔹 Store and analyze data on an SD card for logging distance changes.

## Contributing
Feel free to submit issues or pull requests to improve the project. 🚀

## License
This project is licensed under the **MIT License**. See `LICENSE` for details.

## Author
**Mikhael da Silva** – [GitHub Profile](https://github.com/spacemikha/)

