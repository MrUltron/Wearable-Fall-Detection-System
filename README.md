# Wearable-Fall-Detection-System
A wearable fall detection device using Arduino Nano and MPU6050 IMU sensor that triggers a buzzer alert on sudden impact. Portable, real-time, and ideal for safety-focused applications like elderly care or worker monitoring.
# 🤖 Wearable Fall Detection System

A compact, wearable Arduino-based system that detects when the wearer falls and sounds an alert. Built on an Arduino Nano + IMU sensor and buzzer.  

---

## 🎯 Project Overview

When a sudden, large movement (free-fall + impact) is detected by the IMU, the device triggers a buzzer alarm.  
- **Real-time** detection  
- **Portable** & battery-powered  
- **Expandable**: add Bluetooth, LEDs, data logging

---

## 🧩 Bill of Materials

| Emoji | Component                | Qty | Notes                                  |
|:-----:|--------------------------|:---:|----------------------------------------|
| 📌    | Arduino Nano             | 1   | ATmega328P, 5 V                        |
| 🧲    | MPU-6050 (gyro+accel)    | 1   | I²C interface                         |
| 🔔    | Piezo Buzzer             | 1   | 5 V active buzzer                     |
| 🥽    | Breadboard & Jumper Wires| 1   | For prototyping                       |
| 🔋    | 18650 Li-ion battery + TP4056 charger | 1 | Wearable power source                 |
| ⚙️    | USB Cable                | 1   | For programming Arduino               |

---

## 📐 System Architecture & Wiring


- 🧩 **MPU-6050** connects via **I²C**:  
  - VCC → 5 V  
  - GND → GND  
  - SDA → A4  
  - SCL → A5  
- 🔔 **Buzzer**:  
  - + → D3  
  - – → GND  

---

## ⚙️ Software Setup

1. **Arduino IDE**  
   - Install [Arduino IDE](https://www.arduino.cc/en/software)  
   - Add Board: Tools → Board → “Arduino Nano” (ATmega328P, Old Bootloader)  

2. **Libraries**  
   ```bash
   # In Library Manager:
   # 1) search “MPU6050” by Electronic Cats → install
   # 2) search “Wire” (should be bundled)

